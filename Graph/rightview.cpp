class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    void f(vector<int>& v, int l, Node* r)
{
    if(!r) return;
    if(v.size()==l) v.push_back(r->data);
     f(v, l + 1 ,r->right);
    f(v, l + 1, r->left);
   
}
   vector<int> rightView(Node *root)
    {
       // Your Code here
        vector<int> v;
   f(v, 0, root);
   return v;
    }
};
