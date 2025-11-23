class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count =0;
        //int final =0;
        int digisum=0;
        for(int i=0;i<k;i++){
            digisum+=arr[i];
        }
        if(digisum/k >= threshold){
            count++;
        }
        for(int i=k;i<arr.size();i++){
            digisum+=arr[i];
            digisum-=arr[i-k];
            if((digisum/k)>=threshold)
            count++;
        }
        
        return count;
        
    }
};