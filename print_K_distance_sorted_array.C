
Given an array of positive, unique, increasingly sorted numbers A, e.g. A = [1, 2, 3, 5, 6, 8, 9, 11, 12, 13]. Given a positive value K, e.g. K = 3. Output all pairs in A that differ exactly by K.
e.g. 2, 5
3, 6
5, 8
6, 9
8, 11
9, 12
what is the runtime for your code?


var a = [1, 2, 3, 5, 6, 8, 9, 11, 12, 13];

function differByK(arr, k) {
	if(!arr || !arr.length) {
        throw 'Invalid array input';
    }
    if(k<;0) {
    	throw 'Invalid k input';
    }
    
    var i = 0, j = 1, results = [];
    while(j<arr.length) {
    	var diff = arr[j] - arr[i];
        if(diff < k) {
            j++;
        } else if(diff > k) {
            i++;
        } else{
            results.push([arr[i], arr[j]]);
            j++;
        }
    }
    return results;
}

console.log(JSON.stringify(differByK(a, 3)));