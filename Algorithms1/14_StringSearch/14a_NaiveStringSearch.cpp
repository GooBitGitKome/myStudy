// C++ program for Naive Pattern
// Searching algorithm
#include <bits/stdc++.h>
using namespace std;

void search(char* pat, char* txt)
{
	int M = strlen(pat);//get the length
	int N = strlen(txt);//get the length

	/* A loop to slide pat[] one by one */
	for (int i = 0; i <= N - M; i++) {
		int j;

		/* For current index i, check for pattern match */
		for (j = 0; j < M; j++)
			if (txt[i + j] != pat[j])
				break;

		if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
			cout << ""
				<< i << endl;
	}
}

// Driver Code
int main()
{

	char txt[10001];//text
	char pat[10000];//pattern
    cin >> txt;
    cin >> pat;
	search(pat, txt);
	return 0;
}

// This code is contributed
// by Akanksha Rai

