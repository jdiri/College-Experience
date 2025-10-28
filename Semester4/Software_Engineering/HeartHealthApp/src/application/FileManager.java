package application;

import java.io.IOException;
import java.nio.file.*;
import java.util.Random;

public class FileManager {

    public static String generatePatientID() {
        return String.format("%05d", new Random().nextInt(100000));
    }

    public static void savePatientInfo(Patient patient) throws IOException {
        String fileName = patient.getPatientID() + "_PatientInfo.txt";
        String content = patient.toString();
        Files.write(Paths.get(fileName), content.getBytes(), StandardOpenOption.CREATE);
    }

    public static void saveCTScanData(String patientID, String totalCACScore, String lmScore, String ladScore,
            String lcxScore, String rcaScore, String pdaScore) throws IOException {
    	String fileName = patientID + "_CTResults.txt";

// Create the content string
    	String content = String.format(
    			"Patient ID: %s\n" +
    					"Total Agatston CAC Score: %s\n" +
    					"Vessel-level Agatston CAC Scores:\n" +
    					"  LM: %s\n" +
    					"  LAD: %s\n" +
    					"  LCX: %s\n" +
    					"  RCA: %s\n" +
    					"  PDA: %s\n",
    					patientID, totalCACScore, lmScore, ladScore, lcxScore, rcaScore, pdaScore
    			);
    	Files.write(Paths.get(fileName), content.getBytes(), StandardOpenOption.CREATE);
    	}
	}

