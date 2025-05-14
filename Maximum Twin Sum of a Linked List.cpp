class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> values;
        ListNode* temp = head;
        while(temp!=nullptr){
            values.push_back(temp->val);
            temp = temp->next;
        }

        int maxSum=0;
        int n = values.size();
        for(int i=0;i<n/2;++i){
            int sum = values[i]+ values[n-1-i];
            maxSum = max(maxSum,sum);
        }
        return maxSum;
    }
};
