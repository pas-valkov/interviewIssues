Write a (console) program that takes a filename and a set of parameters as input. Depending on the parameters, the program should work in three modes:
1.test -f Test.tst -m words -v mother - prints the number of words "mother" in the file "Test.tst"
2.test -f Test.tst -m checksum - prints a 32-bit checksum calculated using the checksum algorithm = word1 + word2 + ... + wordN (word1..wordN are 32-bit words representing the file content)
3. test -h - prints program information and parameter descriptions.