#include <stdio.h>
#include <string.h>

struct student{
    int student_id;
    char full_name[50];
    int age;
    float total_marks;
    float average;
    char grade;
    
};
void input_students(struct student students[5]);
void display_students(struct student students[], int x);
void calculate_average(struct student students[5]);
float calculate_class_av(struct student students[5]);
void assign_grade(struct student students[5]);
int search_student(struct student students[5], int id);
void sort_students(struct student students[5]);
void update_student(struct student *students);
void performance_category(char grade);
void grade_comments(char grade);
void save_to_file(struct student students[5]);
void load_from_file(struct student students[5]);
void clean_string(char *str);


void input_students(struct student students[5]) {

    for (int i = 0; i < 5; i++) {
        printf("\n---------------------------------------------------------\n");
        printf("\nplease enter details for Student %d\n", i + 1);

        do{
            printf("please enter student id: ");
            scanf("%d", &students[i].student_id);
        }while(students[i].student_id < 1);
        
        getchar();
        printf("please enter student full name: ");
        fgets(students[i].full_name, 50, stdin);
        clean_string(students[i].full_name);
        
        do{
            printf("please enter student age(17-25): ");
            scanf("%d", &students[i].age);
        }while (students[i].age < 17 || students[i].age > 25);
        
        do{
            printf("please enter student total marks(0-400): ");
            scanf("%f", &students[i].total_marks);
        }while (students[i].total_marks < 0 || students[i].total_marks > 400);
        
    }
    
    calculate_average(students);
    assign_grade(students);
}


void display_students(struct student students[], int x) {
    printf("\n%-5s %-20s %-5s %-8s %-7s %-5s\n",
           "ID", "Name", "Age", "Marks", "Avg", "Grade");
    printf("---------------------------------------------------------\n");

    for (int i = 0; i < x; i++) {
        printf("%-5d %-20s %-5d %-8.2f %-7.2f %-5c\n",
               students[i].student_id, students[i].full_name, students[i].age,students[i].total_marks,students[i].average, students[i].grade);

        performance_category(students[i].grade);
        grade_comments(students[i].grade);
        printf("\n---------------------------------------------------------\n");
    }
}

void assign_grade(struct student students[5]) {
    for(int i=0; i<5; i++ ){
    if (students[i].average >= 90) students[i].grade = 'A';
    else if (students[i].average >= 80) students[i].grade = 'B';
    else if (students[i].average >= 70) students[i].grade = 'C';
    else if (students[i].average >= 60) students[i].grade = 'D';
    else students[i].grade = 'F';
    }
}
void calculate_average(struct student students[5]) {
    for(int i=0; i<5; i++ ){
    students[i].average = students[i].total_marks / 4;   
    }
    
}
float calculate_class_av(struct student students[5]){
    float sum = 0;
    for(int i=0; i<5; i++ ){
        sum += students[i].average;
    }
    return sum / 5;
}
int search_student(struct student students[5], int id){
    for(int i=0; i<5; i++){
        if (students[i].student_id == id){
            return i;
        }
        else return -1;
    }
}
void sort_students(struct student students[5]) {
    struct student temp;

    for (int i = 0; i < 5 - 1; i++) {
        printf("\nPass %d:\n", i + 1);

        for (int j = 0; j < 5 - i - 1; j++) {
            if (students[j].total_marks < students[j + 1].total_marks) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
        for (int k = 0; k < 5; k++) {
            printf("%.2f ", students[k].total_marks);
        }
        printf("\n");
    }
}
void update_student(struct student *students) {
    int id;
    printf("Enter Student ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < 5; i++) {

      
        if ((students + i)->student_id == id) {

            getchar();  

        
            printf("Enter new full name: ");
            fgets((students + i)->full_name, 50, stdin);
            clean_string(students[i].full_name);

            
            do {
                printf("Enter new age (17-25): ");
                scanf("%d", &(students + i)->age);
            } while ((students + i)->age < 17 || (students + i)->age > 25);

           
            do {
                printf("Enter new total marks (0-400): ");
                scanf("%f", &(students + i)->total_marks);
            } while ((students + i)->total_marks < 0 ||
                     (students + i)->total_marks > 400);

            
            calculate_average(students + i);
            assign_grade(students + i);

            printf("Record Updated Successfully\n");
            return;        }
    }

    printf("Student Not Found\n");
}
void performance_category(char grade){
    switch (grade){
        case 'A': printf("P: Excellent Performance ^_^\n");
        break;
        case 'B': printf("P: Good Performance *_*\n");
        break;
        case 'C': printf("P: Satisfactory Performance @_@\n");
        break;
        default:
        printf("P: Performance Needs Improvement -_-\n");
    }
    
}
void grade_comments(char grade){
    if (grade == 'A'){
        printf("Comment: Excellent work stay in the top");
    }
    else if (grade == 'B'){
        printf("Comment: Good job need a little push to reach the top\n");
    }
    else if (grade == 'C'){
        printf("Comment: You are in the average keep pushing yoursel to the top\n");
    }
    else{
        printf("Comment: You should work hard and focus in studying you can do it just start\n");
    }
}
void save_to_file(struct student students[5]){
    FILE *fptr;
    fptr= fopen("students_data.text", "w");
    for (int i = 0; i < 5; i++) {
        fprintf(fptr, "%d,%s,%d,%.2f,%.2f,%c\n",
            students[i].student_id, students[i].full_name, students[i].age,students[i].total_marks,students[i].average, students[i].grade);
    }
    fclose(fptr);
    printf("students data saved successfully to the file");
}
void load_from_file(struct student students[5]){
    FILE *fptr;
    fptr= fopen("students_data.text", "r");
    if (fptr == NULL) {
        printf("File not found\n");
        return;
	}
    for (int i = 0; i < 5; i++) {
        fprintf(fptr, "%d,%49[^,],%d,%.2f,%.2f,%c\n",
            students[i].student_id, students[i].full_name, students[i].age,students[i].total_marks,students[i].average, students[i].grade);
            clean_string(students[i].full_name);
    }
    fclose(fptr);
    printf("students data loaded successfully from the file");
}
void clean_string(char *str) {
    str[strcspn(str, "\r\n")] = '\0';
}





int main(){
    struct student students[5];
    int choice, id, index;

    do {
        printf("\n==========================================\n");
        printf("STUDENT MANAGEMENT SYSTEM\n");
        printf("==========================================\n");
        printf("1. ENTER STUDENT DATA\n");
        printf("2. DISPLAY ALL STUDENTS\n");
        printf("3. SEARCH FOR STUDENT\n");
        printf("4. SORT STUDENTS BY MARKS\n");
        printf("5. CALCULATE CLASS STATISTICS\n");
        printf("6. SAVE DATA TO FILE\n");
        printf("7. LOAD DATA FROM FILE\n");
        printf("8. UPDATE STUDENT RECORD\n");
        printf("9. EXIT\n");
        printf("==========================================\n");
        printf("Enter your choice (1-9): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                input_students(students);
                break;

            case 2:
                display_students(students, 5);
                break;

            case 3:
                printf("Enter Student ID to search: ");
                scanf("%d", &id);
                index = search_student(students,id);
                if (index != -1) {
                    printf("Student Found:\n");
                    display_students(&students[index], 1);
                } else {
                    printf("Student Not Found\n");
                }
                break;

            case 4:
                printf("\nstudents before sorting\n");
                display_students(students, 5);
                sort_students(students);
                printf("\nstudents after sorting\n");
                display_students(students, 5);
                break;

            case 5:
                printf("Class Average = %.2f\n",
                       calculate_class_av(students));
                break;

            case 6:
                save_to_file(students);
                break;

            case 7:
                load_from_file(students);
                break;

            case 8:
                update_student(students);
                break;

            case 9:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 9);

    return 0;
    
}
    

