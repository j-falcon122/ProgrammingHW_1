/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import java.util.LinkedList;

public class WaitingRoom extends Thread{
    
    int maxCapacity = 3;
    LinkedList<Student> studentQueue = null;
    Professor professor;
    
    public WaitingRoom(int capacity, Professor professor){
        
        this.maxCapacity = capacity;
        studentQueue = new LinkedList<Student>(); 
        this.professor = professor;
    }
    
    public synchronized boolean hasSpace(){
        if (studentQueue.size() < maxCapacity){
            return true; 
        }
        return false;
    }
    
    public synchronized void enterWaitingRoom(Student student){
        if (this.hasSpace()){
            studentQueue.addLast(student);
            student.state = Student.WAITING;
            System.out.println("Student id = "+student.id+" entered in the waiting room");
            if (professor.isSleeping()) {
                synchronized(professor){
                    professor.notify();
                    System.out.println("Student "+ student.id +" woke up the professor");
                }
            }
        }
        else {
            System.out.println("No space in the waiting room, Student "+ student.id +" goes back to study.");
        }
    }
    
    public synchronized Student getNextStudent(){
        
        Student student = null;
        if (studentQueue.size()>0){
            student = studentQueue.remove();
            System.out.println("Student id = "+student.id+" left in the waiting room");
        }
        return student;
    }
    
}
