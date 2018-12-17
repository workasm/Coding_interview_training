

public class powers2i5j {


    public static void main(String[] args) {
        int[] ans = new int[100];
        ans[0] = 1;
        int m = 0; //2
        int n = 0; //5
        int i = 1;

        for (int j = 1; j < 100; j++) {
            int n5 = ans[n] * 5;
            int m2 = ans[m] * 2;
            if (n5 < m2) {
                ans[i] = n5;
                i++;
                System.out.print(n5 + ", ");
                n++;
            } else if (n5 > m2) {
                ans[i] = m2;
                i++;
                System.out.print(m2 + ", ");
                m++;
            } else {
                ans[i] = n5;
                i++;
                System.out.print(m2 + ", ");
                m++;
                n++;
            }
        }
    }
}


void print2i5() {

// print 2^i*5^j increasing order

int a[100];
a[0] = 1;

int i2 = 0, i5 = 0;
for(int i = 1; i < 100; i++) {

    if(a[i2]*2 < a[i5]*5) {
        a[i] = a[i2]*2;
        i2++;
    } else {
        a[i] = a[i5]*5;
        i5++;
        if(a[i2]*2 == a[i5]*5)
            i2++;
    }
    printf("%d ", a[i]);
}
}
