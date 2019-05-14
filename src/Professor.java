/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import java.util.Random;



public class Professor extends Thread {
    
    int tutorMaxTime = 10000;
    int limitTutorTime = 30000;  //when sum of tutoring time reachs the limit, go home 
    SyncProfStudents sps;
    long endTime;
    
    boolean isSleeping = true;
    
    public Professor(int tutorAvgTime, SyncProfStudents sps){
        this.tutorMaxTime = tutorAvgTime;
        this.sps = sps;
        this.endTime = System.currentTimeMillis() + limitTutorTime;
    }
    
    public synchronized boolean isSleeping() {
        return this.isSleeping;
    }
    
    public void run(){
        
        Random rand = new Random();
        try{
            int totalTutorTime = 0;
            while (System.currentTimeMillis() <= this.endTime){

                Student currentStudent = SyncProfStudents.waitRoom.getNextStudent();
                if (currentStudent!=null){
                    isSleeping = false;
                    currentStudent.state =  Student.TUTORING;
                    int tutorTime = rand.nextInt(tutorMaxTime);
                    if (tutorTime<2000){
                        tutorTime = 2000;
                    }
                    totalTutorTime = totalTutorTime + tutorTime;
                    System.out.println("Professor tutoring student "+currentStudent.id+" for "+tutorTime+"ms.");
                    Thread.sleep(tutorTime);
                    System.out.println("Student "+ currentStudent.id + "  leaves tutoring");
                    currentStudent.startStudy(); //send student to study again
                    
                    System.out.println("Professor worked for "+totalTutorTime+"ms.");

                }else{
                    //wait for one student
                    synchronized(this){
                        isSleeping = true;
                        System.out.println("Professor resting");
                        wait(limitTutorTime);
                    }
                }
            }
            sps.end();
            
        }catch(Exception e){
            e.printStackTrace();
        }
    }
    
}
