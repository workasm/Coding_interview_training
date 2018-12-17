
#include <stdio.h>


void print_triplets(int *a, int n) {

    for(int i = 0; i < n; i++) {
        int x = a[i];
        int i1 = 0, i2 = n-1;

        while(i1 < i2) {
            if(i1 == i)
                i1++;
            else if(i2 == i)
                i2--;
            else if(a[i1] + a[i2] < x)
                i1++;
            else if(a[i1] + a[i2] > x)
                i2--;
            else {
                printf("%d + %d = %d\n", a[i1], a[i2], x);
//                 break;
                i1++;
            }
        }
    }
}


int main() {

    int A[] = {1, 2, 4, 5, 7, 11, 14, 20, 22, 25};
    int n = sizeof(A) / sizeof(int);
    print_triplets(A, n);
    
    return 1;
}



import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class PutSpaces {
        private List<String>[] found;
        private Set<String> dictionary;

        @SuppressWarnings("unchecked")
        public List<String> putSpaces(Set<String> dictionary, String str) {
                this.dictionary = dictionary;
                found = new List[str.length()];
                return putSpaces(str, 0);
        }

        private List<String> putSpaces(String str, int start) {
                if (found[start] != null)
                        return found[start];

                List<String> result = new ArrayList<String>();
   for (int i=0; i<str.length();++i) {
       String word = str.substring(0, i+1);
       if(!dictionary.contains(word))
           continue;
           
       if(word.equals(str)) {
           result.add(word);
       } else {
           List<String> next = putSpaces(str.substring(i+1), start+i+1);
           for(String phrase : next) {
               result.add(word + " " + phrase);
           }
       }
    }
      return found[start] = result;
  }

        public static void main(String[] args) {
                Set<String> dictionary = new HashSet<String>();
                dictionary.addAll(Arrays.asList(new String[]{"this", "i", "saw", "is", "a", "awe", "we", "some", "awesome"}));
                String str = "thisisawesome";
                PutSpaces putSpaces = new PutSpaces();
                List<String> phrases = putSpaces.putSpaces(dictionary, str);
                System.out.println(phrases);
        }

}