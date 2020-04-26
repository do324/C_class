/*----------------------------------------
Name : doyeon kim	
ID   : 139766166
Email: dkim126@myseneca.ca
-----------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int isJediMaster(const char name[]) {
  int isJedi = 0;
  char jedi_name[31];
  FILE *fp = NULL;
  fp = fopen("jedi_master.txt", "r");

  if (fp != NULL) {
	  while (fscanf(fp, "%[^\n]%*c", jedi_name) == 1) {
		  if (strcmp(jedi_name, name) == 0) {
			  isJedi = 1;
		  }
	  }

	  fclose(fp);
  }
  else {
	  printf("Could not open the file\n");
  }
  return isJedi;
}


void formatJediPhoneRecord(char formattedRecord[], const char fullName[], const char npa[], const char co[], const char number[]) {
    int i, namelen, test = 0;
	char temporary[20];
	char originalName[45];
	strcpy(originalName, fullName);


	namelen = strlen(originalName);
	test = isJediMaster(originalName);
	if (namelen > 16) {
		strncpy(temporary, originalName, 14);
		temporary[14] = '\0';
		strcpy(originalName, temporary);
		strcat(originalName, "..");
	}
	else {
		for (i = 0; i < 16 - namelen; i++) {
			strcat(originalName, " ");
		}
	}
	strcpy(formattedRecord, originalName);
	strcat(formattedRecord, " (");
	strcat(formattedRecord, npa);
	strcat(formattedRecord, ") ");
	strcat(formattedRecord, co);
	strcat(formattedRecord, "-");
	strcat(formattedRecord, number);
	if (test == 1) {
		strcat(formattedRecord, " Jedi Master");
	}
}





/* Example formatted strings:
Padme Amidala    (418) 555-0105
Mace Windu       (438) 555-0155 Jedi Master.
Emperor Palpat.. (450) 555-0143
*/