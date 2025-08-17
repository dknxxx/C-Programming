#include <stdio.h>

int main(void) {
	int grade[5][5];
	float quiz_total[5];
	float student_total_score[5], quiz_high_score[5] = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f}, quiz_low_score[5] = {100.0f, 100.0f, 100.0f, 100.0f, 100.0f}; 

	for (int i = 0; i < 5; i++) {
		printf("Enter row %d: ", i);
		scanf("%d %d %d %d %d", &grade[i][0], &grade[i][1], &grade[i][2], &grade[i][3], &grade[i][4]);
	}

	for (int i = 0; i < 5; i++) {
		student_total_score[i] = 0.0f;
		quiz_total[i] = 0.0f;
		for (int j = 0; j < 5; j++) {
			student_total_score[i] += grade[i][j];
			quiz_total[i] += grade[j][i];
			if (grade[j][i] >= quiz_high_score[i])
					quiz_high_score[i] = grade[j][i];
			if (grade[j][i] <= quiz_low_score[i])
					quiz_low_score[i] = grade[j][i];
		}
	}

	for (int i = 0; i < 5; i++) {
		printf("Student %d Total: %4.2f, Average: %4.2f\n", i, student_total_score[i], student_total_score[i] / 5);
		printf("Quiz %d Average: %4.2f, Quiz High: %4.2f, Quiz Low: %4.2f:\n", i, quiz_total[i] / 5, quiz_high_score[i], quiz_low_score[i]);
 	}

	printf("\n");
	return 0;
}
