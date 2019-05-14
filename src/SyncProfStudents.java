/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Miguel
 */
public class SyncProfStudents {

    int numStudents = 10;
    int studyMaxTime = 12000;
    static WaitingRoom waitRoom;
    
    ArrayList<Student> studentList = new ArrayList<Student>();
    
    public void start(String[] args){
        
        System.out.println("Optional parameters: \n numberOfStudent (default = 10) studyMaxTime (default = 12000) ");
       
        if (args.length>0){
            numStudents = Integer.valueOf(args[0]);
        }
        
        if (args.length>1){
            studyMaxTime = Integer.valueOf(args[1]);
        }
        
        
        for(int i=0; i<numStudents; i++){
            try {
                Student student = new Student(studyMaxTime);
                studentList.add(student);
                student.startStudy();
                Thread.sleep(5);
            } catch (InterruptedException ex) {
                ex.printStackTrace();
                //Logger.getLogger(SyncProfStudents.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        
        Professor prof = new Professor(15000, this);
        waitRoom = new WaitingRoom(3, prof);
        prof.start();
    }
    
    public void end(){
        
        System.out.println("Professor is tired, going home. Bye!");
        System.exit(0);
    }
    
    public static void main(String[] args) {
        
        SyncProfStudents sps = new SyncProfStudents();
        sps.start(args);
    }
    
}
