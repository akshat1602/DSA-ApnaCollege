#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class SegmentTree{
    vector <int> tree;
    int n;

    void buildTree(vector <int> &nums, int st, int end, int node){
        if(st == end){
            tree[node] = nums[st];
            return;
        }

        int mid = st + (end-st)/2;

        buildTree(nums, st, mid, 2*node+1);
        buildTree(nums, mid+1, end, 2*node+2);

        tree[node] = max(tree[2*node+1], tree[2*node+2]);
    }

    int maxQuery(int qi, int qj, int si, int sj, int node){ //O(logn)

        //No overlap
        if(qi > sj || qj < si){ 
            return INT_MIN;
        }

        //Complete
        if(si >= qi && sj <= qj){
            return tree[node];
        }

        //Partial
        int mid = si + (sj - si)/2;

        int leftMax = maxQuery(qi, qj, si, mid, 2*node+1);
        int rightMax = maxQuery(qi, qj, mid+1, sj, 2*node+2);

        return max(leftMax, rightMax);
    }

    void updateUtil(int idx, int newVal, int st, int end, int node){ //O(logn)
        if(st == end){
            tree[node] = newVal;
            return;
        }

        int mid = st + (end - st)/2;

        if(idx >= st && idx <= mid){ //left
            updateUtil(idx, newVal, st, mid, 2*node+1);
        }
        else{ //right
            updateUtil(idx, newVal, mid+1, end, 2*node+2);
        }

        tree[node] = max(tree[2*node+1], tree[2*node+2]);
    }

public:
    SegmentTree(vector <int> &nums){
        n = nums.size();
        tree.resize(4*n);
        buildTree(nums, 0, n-1, 0);
    }

    void printTree(){
        for(int el : tree){
            cout<<el<<" ";
        }
        cout<<endl;
    }

    int rangeQuery(int qi, int qj){
        maxQuery(qi, qj, 0, n-1, 0);
    }

    void updateQuery(int idx, int newVal){
        updateUtil(idx, newVal, 0, n-1, 0);
    }
};

int main() {
    //Range sum queries
    vector <int> nums = {6, 8, -1, 2, 17, 1, 3, 2, 4};

    SegmentTree st(nums);
    st.printTree();

    cout<<st.rangeQuery(2, 5)<<endl;
    cout<<st.rangeQuery(5, 8)<<endl;

    cout<<endl;
    cout<<"After updation"<<endl;
    st.updateQuery(4,5);
    cout<<st.rangeQuery(0, 8)<<endl;
    return 0;
}