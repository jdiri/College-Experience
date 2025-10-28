package application;

public class Patient {
    private String patientID;
    private String fullName;
    private String dateOfBirth;
    private String address;
    private String contactNumber;
    private String emailAddress;
    private String examDate;

    // Constructor
    public Patient(String patientID, String fullName, String dateOfBirth, String address,
                   String contactNumber, String emailAddress, String examDate) {
        this.patientID = patientID;
        this.fullName = fullName;
        this.dateOfBirth = dateOfBirth;
        this.address = address;
        this.contactNumber = contactNumber;
        this.emailAddress = emailAddress;
        this.examDate = examDate;
    }

    // Getters and Setters
    public String getPatientID() {
        return patientID;
    }

    public void setPatientID(String patientID) {
        this.patientID = patientID;
    }

    public String getFullName() {
        return fullName;
    }

    public void setFullName(String fullName) {
        this.fullName = fullName;
    }

    public String getDateOfBirth() {
        return dateOfBirth;
    }

    public void setDateOfBirth(String dateOfBirth) {
        this.dateOfBirth = dateOfBirth;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public String getContactNumber() {
        return contactNumber;
    }

    public void setContactNumber(String contactNumber) {
        this.contactNumber = contactNumber;
    }

    public String getEmailAddress() {
        return emailAddress;
    }

    public void setEmailAddress(String emailAddress) {
        this.emailAddress = emailAddress;
    }

    public String getExamDate() {
        return examDate;
    }

    public void setExamDate(String examDate) {
        this.examDate = examDate;
    }

    @Override
    public String toString() {
        return "Patient ID: " + patientID + "\n" +
               "Full Name: " + fullName + "\n" +
               "Date of Birth: " + dateOfBirth + "\n" +
               "Address: " + address + "\n" +
               "Contact Number: " + contactNumber + "\n" +
               "Email Address: " + emailAddress + "\n" +
               "Exam Date: " + examDate + "\n";
    }
}

