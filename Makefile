CC = clang
CFLAGS = -Wall -Wextra -pedantic -std=c11 -Wshadow -Wconversion

TARGET_FILE_BASE_NAME = day-01-1
TARGET_SAMPLE_FILE = day-01-1.txt

output: src\$(TARGET_FILE_BASE_NAME).c
	$(CC) -o bin\$(TARGET_FILE_BASE_NAME).exe  src\$(TARGET_FILE_BASE_NAME).c $(CFLAGS)

run:
	powershell "Get-Content samples\$(TARGET_SAMPLE_FILE) | bin\$(TARGET_FILE_BASE_NAME).exe; $$null"

clean:
	powershell "Remove-Item bin\$(TARGET_FILE_BASE_NAME).exe; $$null"


