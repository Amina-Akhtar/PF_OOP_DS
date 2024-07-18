//#include<iostream>
//using namespace std;
//int length(char word[10])
//{
//   // calculating the length of word
//	int sum = 0;
//	for (int i = 0; word[i] != '\0'; i++)
//	{
//		sum++;
//	}
//	return sum;
//}
//int calculate(char input[], char word[], int siz,int word_size)
//{
//    //finding the frequency of entered word ignoring case sensitivity
//    int count = 0, hint = 0, k = 0;
//    for (int i = 0; i < siz; i++)
//    {
//        if (word[k] == input[i]||(int) word[k]+32 == (int)input[i]|| (int)word[k] == (int)input[i]+32)
//        {
//            count++;
//            k++; 
//        }
//        if (count == word_size)
//        {
//            hint++;
//            k = 0;
//            count = 0;
//
//        }
//    }
//    return hint;
//}
//void length_word(char **help, int k, int temp[])
//{
//    //finding the length of each word in the sentence
//    int sum = 0,u=0;
//    for (int i = 0; i < k; i++,sum=0)
//    {
//        for (int j = 0; help[i][j] != '\0'; j++)
//        {
//            sum++;
//        }
//        temp[u++] = sum;
//    }
//}
//void frequency(char** help, int temp[], int freq[], int k)
//{
//   int freq_count = 0, hint = 0,place=0,oop=0;
//    for (int i = 0; i < k;i++,oop=0,hint=0)
//    {
//        char* inter = new char[temp[i]];
//        for (int j = 0; help[i][j] != '\0'; j++)
//        {
//            inter[j] = help[i][j];
//        }
//        //calculating frequency of each word one by one
//        for(int l=0;l<=temp[oop]&&oop<k;)
//        {   
//            if (l == temp[oop])
//            {
//                if (hint == 0)
//                {
//                    freq_count = 0;
//                }
//                oop++;
//                l = 0;
//                continue;
//            }
//            if (help[oop][l] == inter[l] || (int)help[oop][l] + 32 == (int)inter[l] || (int)help[oop][l] == (int)inter[l] + 32)
//            {
//                freq_count++;
//
//                if (freq_count == temp[oop])
//                {
//                    hint++;
//                    freq_count = 0;
//                    l++;
//                }
//                else
//                {
//                    l++;
//                }
//            }
//            else
//            {
//                l++;
//            }
//        }
//        freq[place++] = hint;  
//    }
//}
//
//int main()
//{
//    
//    char choice = ' ';
//	int siz,word_size=0,k=0;
//	char* word = new char[10];
//	cout << "Enter the size of the array:" ;
//	cin >> siz;
//    char** help = new char * [siz ];
//        for (int i = 0; i < (siz ); i++)
//        {
//            help[i] = new char[20];
//        }
//        //taking user input
//	cout << "Enter the sentence : " << endl;
//	char  *input = new char[siz+1];
//	cin.ignore();
//	cin.getline(input, siz);
//    //handling of repetition of the loop
//    cout << "_______________________________________" << endl;
//    while (choice == 'y' || choice == 'Y' || choice == ' ')
//    {
//        int found = 0;
//        cout << "Enter the word to find the frequency. " << endl;
//        cin.ignore();
//        cin.clear();
//        cin.getline(word, siz);
//        cout << "_______________________________________" << endl;
//        word_size = length(word);
//        found = calculate(input, word, siz, word_size);
//        cout << "The word is found " << found << " times. " << endl;
//        cout << "_______________________________________" << endl;
//        cout << "To find frequency of another word,press y." << endl;
//        cout << "Entering anything else will display  the frequency of all the words." << endl;
//        cin >> choice;
//        //calculating frequency of each word
//        if (choice != 'y' && choice != 'Y')
//        {
//            for (int i = 0,j=0; i < siz; i++)
//            {
//                //checking the condition ignoring punctuation
//               if ( input[i] == '\0' ||((int)input[i]>= 32&& (int)input[i]<=47)||((int)input[i]>=58&& (int)input[i]<=64)||((int)input[i]>=91&& (int)input[i]<=96))
//                {
//                   help[k][j] = '\0';
//                   j = 0;
//                   k++;
//                   continue;
//                }
//               else
//               {
//                   help[k][j] = input[i];
//                   j++;
//               }
//            }
//        }
//    }
//    int* temp = new int[k];
//    int* freq = new int[k];
//    length_word(help, k, temp);
//    frequency(help, temp, freq, k);
//    //displaying the output
//    cout << "________________________________________________" << endl;
//    for (int i = 0; i < k; i++)
//    {
//        for (int j = 0; help[i][j] != '\0'; j++)
//        {
//            cout << help[i][j];
//        }
//        if (freq[i] == 0)
//        {
//            continue;
//        }
//        cout << " :" << freq[i] << " times" << endl;
//    }
//    cout << "________________________________________________" << endl;
//    //deallocating the memory
//  // delete[]temp;
//    delete[]freq;
//    delete[]input;
//    delete[]word;
//   /* for (int i = 0; i < siz; i++)
//    {
//        delete[]help[i];
//        help[i] = NULL;
//    }
//    delete[]help;*/
//}