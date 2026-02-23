class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalsize = nums1.size() + nums2.size();
        int m = nums1.size();
        int n = nums2.size();

        int ele1 = -1;
        int ele2 = -1;
        int i = 0;
        int j = 0;

        int k = 0;

        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                if (k == totalsize / 2 - 1) {
                    ele1 = nums1[i];
                }
                if (k == totalsize / 2) {
                    ele2 = nums1[i];
                    
                }

                i++;

            } else {
                if (k == totalsize / 2 - 1) {
                    ele1 = nums2[j];
                }
                if (k == totalsize / 2) {
                    ele2 = nums2[j];
                    
                }

                j++;
            }
            k++;
        }

        while (i < m) {
            if (k == totalsize / 2 - 1) {
                ele1 = nums1[i];
            }
            if (k == totalsize / 2) {
                ele2 = nums1[i];
                
            }

            i++;
            k++;
        }

        while (j < n) {
            if (k == totalsize / 2 - 1) {
                ele1 = nums2[j];
            }
            if (k == totalsize / 2) {
                ele2 = nums2[j];
                
            }

            j++;
            k++;
        }

        if(totalsize%2==1) return ele2;
        else return (ele1+ele2)/2.0;
    }
};