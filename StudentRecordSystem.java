import java.util.*;

/* ==============================================================
   STUDENT RECORD MANAGEMENT SYSTEM
   IMPLEMENTATION : OOPS (JAVA)
   DATA STRUCTURE : ARRAYLIST (COLLECTION FRAMEWORK)
   INTERFACE      : COMMAND LINE (MENU DRIVEN)
   ============================================================== */

/* ================= STUDENT CLASS =================
   Represents a single student record
   ================================ */
class Student {
    private int id;
    private String name;
    private int age;
    private String course;
    private float marks;

    // Constructor
    Student(int id, String name, int age, String course, float marks) {
        this.id = id;
        this.name = name;
        this.age = age;
        this.course = course;
        this.marks = marks;
    }

    // Getters and Setters (Encapsulation)
    public int getId() { return id; }
    public String getName() {
         return name; 
        }
    public int getAge() { 
        return age;
     }
    public String getCourse() {
         return course; 
        }
    public float getMarks() { 
        return marks; 
    }

    public void setName(String name) { 
        this.name = name; 
    }
    public void setAge(int age) { 
        this.age = age;
     }
    public void setCourse(String course) { 
        this.course = course;
     }
    public void setMarks(float marks) {
         this.marks = marks; 
        }
}

/* ================= STUDENT MANAGER CLASS =================
   Backend logic using ArrayList
   =============================================== */
class StudentManager {
    private ArrayList<Student> students = new ArrayList<>();

    // ADD student
    public void addStudent(Student s) {
        students.add(s);
        System.out.println("Student record added successfully.");
    }

    // DISPLAY students
    public void displayStudents() {
        if (students.isEmpty()) {
            System.out.println("No student records found.");
            return;
        }
        System.out.println("\n--- STUDENT RECORDS ---");
        for (Student s : students) {
            System.out.println("ID: " + s.getId() +
                               " | Name: " + s.getName() +
                               " | Age: " + s.getAge() +
                               " | Course: " + s.getCourse() +
                               " | Marks: " + s.getMarks());
        }
    }

    // SEARCH student
    public Student searchStudent(int id) {
        for (Student s : students) {
            if (s.getId() == id)
                return s;
        }
        return null;
    }

    // DELETE student
    public boolean deleteStudent(int id) {
        Iterator<Student> it = students.iterator();
        while (it.hasNext()) {
            if (it.next().getId() == id) {
                it.remove();
                return true;
            }
        }
        return false;
    }
}

/* ================= MAIN CLASS (FRONTEND) ================= */
 class StudentRecordSystem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StudentManager manager = new StudentManager();
        int choice;

        do {
            System.out.println("\n===== STUDENT RECORD MANAGEMENT SYSTEM =====");
            System.out.println("1. Add Student");
            System.out.println("2. Display Students");
            System.out.println("3. Search Student");
            System.out.println("4. Update Student");
            System.out.println("5. Delete Student");
            System.out.println("6. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter ID: ");
                    int id = sc.nextInt();
                    System.out.print("Enter Name: ");
                    String name = sc.next();
                    System.out.print("Enter Age: ");
                    int age = sc.nextInt();
                    System.out.print("Enter Course: ");
                    String course = sc.next();
                    System.out.print("Enter Marks: ");
                    float marks = sc.nextFloat();

                    manager.addStudent(new Student(id, name, age, course, marks));
                    break;

                case 2:
                    manager.displayStudents();
                    break;

                case 3:
                    System.out.print("Enter Student ID to search: ");
                    Student s = manager.searchStudent(sc.nextInt());
                    if (s != null) {
                        System.out.println("ID: " + s.getId() +
                                           " | Name: " + s.getName() +
                                           " | Age: " + s.getAge() +
                                           " | Course: " + s.getCourse() +
                                           " | Marks: " + s.getMarks());
                    } else {
                        System.out.println("Student not found.");
                    }
                    break;

                case 4:
                    System.out.print("Enter Student ID to update: ");
                    int uid = sc.nextInt();
                    Student us = manager.searchStudent(uid);
                    if (us != null) {
                        System.out.print("Enter New Name: ");
                        us.setName(sc.next());
                        System.out.print("Enter New Age: ");
                        us.setAge(sc.nextInt());
                        System.out.print("Enter New Course: ");
                        us.setCourse(sc.next());
                        System.out.print("Enter New Marks: ");
                        us.setMarks(sc.nextFloat());
                        System.out.println("Student record updated successfully.");
                    } else {
                        System.out.println("Student not found.");
                    }
                    break;

                case 5:
                    System.out.print("Enter Student ID to delete: ");
                    if (manager.deleteStudent(sc.nextInt()))
                        System.out.println("Student record deleted successfully.");
                    else
                        System.out.println("Student not found.");
                    break;

                case 6:
                    System.out.println("Exiting program...");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }
        } while (choice != 6);

        sc.close();
    }
}
