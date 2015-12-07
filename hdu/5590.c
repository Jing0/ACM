/*
 * =====================================================================================
 *
 *       Filename:  5590.c
 *
 *    Description:  
 *    After getting 600 scores in NOIP ZYB(ZJ−267) begins to work with biological questions.Now he give you a simple biological questions:
 *    he gives you a DNA sequence and a RNA sequence,then he asks you whether the DNA sequence and the RNA sequence are 
 *    matched.
 *    The DNA sequence is a string consisted of A,C,G,T;The RNA sequence is a string consisted of A,C,G,U.
 *    DNA sequence and RNA sequence are matched if and only if A matches U,T matches A,C matches G,G matches C on each position. 
 *    Input
 *    In the first line there is the testcase T.
 *    For each teatcase:
 *    In the first line there is one number N.
 *    In the next line there is a string of length N,describe the DNA sequence.
 *    In the third line there is a string of length N,describe the RNA sequence.
 *    1≤T≤10,1≤N≤100
 *    Output
 *    For each testcase,print YES or NO,describe whether the two arrays are matched.
 *    Sample Input
 *    2
 *    4
 *    ACGT
 *    UGCA
 *    4
 *    ACGT
 *    ACGU
 *    Sample Output
 *    YES
 *    NO  
 *
 *        Created:  12/07/2015 14:11:04
 *       Compiler:  gcc
 *
 *         Author:  Jackie Kuo (http://jackiekuo.com), j.kuo2012@gmail.com
 *
 * =====================================================================================
 */

#include <stdio.h>
int foo(char d, char r) {
	if (d == 'G' && r == 'C') {
		return 1;
	} else if (d == 'C' && r == 'G') {
		return 1;
	} else if (d == 'A' && r == 'U') {
		return 1;
	} else if (d == 'T' && r == 'A') {
		return 1;
	}
	return 0;
}
int main() {
	int t;
	char dna[105], rna[105];
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		scanf("%s", dna);
		scanf("%s", rna);
		int i, flag = 1;
		for (i = 0; i < n; ++i) {
			if (!foo(dna[i], rna[i])) {
				flag = 0;
				break;
			}
		}
		printf("%s\n", flag?"YES":"NO");
	}
	return 0;
}
