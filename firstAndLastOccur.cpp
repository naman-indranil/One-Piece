#include<bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n , int x );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


// } Driver Code Ends


vector<int> find(int arr[], int n , int x )
{
    // code here
    int low=0,up=0,flag=0;
    int i;
    for(i=0;i<n;i++){
        if(arr[i]==x){
            low=i;
            flag=1;
            break;
        }
    }
    i++;
    for(;i<n;i++){
        if(arr[i]==x){
            up++;
        }
        else{
            break;
        }
    }
    up=up+low;
    
    vector<int> ar;
    if(flag!=0){
    ar.push_back(low);
    ar.push_back(up);}
    else{
       ar.push_back(-1);
    ar.push_back(-1); 
    }
    return ar;
}