
void minizeDistance(int *a, int *b, int *c, int n) {

    int mini, minj, mink;
    int minval = 1<<24;

        int i=0, j=0, k=0;
        while (true) {
            int curMin = std::max(a[i] - b[j],
                std::max(b[j] - c[k], c[k] - a[i]));
            if (minVal == (1<<24) || curMin < minVal) {
                minVal = curMin;
                mini=i,minj=j,mink=k;
            }
            boolean canIncI = i != a.length-1;
            boolean canIncJ = j != b.length-1;
            boolean canIncK = k != c.length-1;
            if (!canIncI && !canIncJ && !canIncK)
                break;
            if (canIncI && (!canIncJ || a[i] < b[j])
                && (!canIncK || a[i] < c[k]))
                ++i;
            else if (canIncJ && (!canIncK || b[j] < c[k]))
                ++j;
            else
                ++k;

        }
        return minIndexes;
    }
}
