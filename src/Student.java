/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.Random;

public class Student extends Thread{
    
    final static int STUDYING = 0;
    final static int WAITING = 1;
    final static int TUTORING = 2;
    static int nextId = 0;

    int studyMaxTime;
    int state = STUDYING;  
    int id = 0;
    
    
    public Student(int studyMaxTime) {
        
        this.studyMaxTime = studyMaxTime;
        this.id = nextId;
        nextId++;
        
    }
    
    public void startStudy(){
        
        this.state=Student.STUDYING;
        StudyThread studyAct = new StudyThread(this);
        studyAct.start();
    }
    
    public String toString(){
        return "Id = "+id+" state = "+state;
    }
    

    
    private class StudyThread extends Thread{
    
        Student student;

        public StudyThread(Student student){
            this.student = student;
        }

        public void run(){

            Random rand = new Random();

            try{
                while(student.state==Student.STUDYING){
                    int studyTime = rand.nextInt(studyMaxTime);
                    if (studyTime<2000){
                        studyTime = 2000;
                    }

                    System.out.println("Student "+id+" will study for "+studyTime+" ms.");
                    Thread.sleep(studyTime);
                    System.out.println("Student "+id+" ready.");
                    SyncProfStudents.waitRoom.enterWaitingRoom(student);
                }
            }catch(Throwable tr){
                tr.printStackTrace();
            }
        }
    }
    
}
