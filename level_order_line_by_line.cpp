#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
void levelOrder(struct Node* node);
/* Helper function to test mirror(). Given a binary
   search tree, print out its data elements in
   increasing sorted order.*/
void inOrder(struct Node* node)
{
  if (node == NULL)
    return;
  inOrder(node->left);
  printf("%d ", node->data);
  inOrder(node->right);
}
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     levelOrder(root);
     cout << endl;
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* A binary tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
//You are required to complete this method
void levelOrder(Node* node)
{
  //Your code here
  queue<Node*> q;
  if(node == NULL)
    return;
  q.push(node);
  q.push(NULL);
  while(q.size() != 1){
      if(q.front())
        cout<<q.front()->data<<" ";
      else{
          cout<<"$"<<" ";
          q.push(NULL);
      }
      if(q.front() != NULL && q.front()->left)
        q.push(q.front()->left);
      if(q.front() != NULL && q.front()->right)
        q.push(q.front()->right);
      q.pop();
  }
  cout<<"$";
}
