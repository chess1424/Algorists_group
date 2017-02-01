//Problem statment: http://poj.org/problem?id=1308

#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>

using namespace std;

typedef struct node{
  bool visited;
  int parents;
  vector<node*> children;
}node;

void dfs(node** root)
{
  (*root) -> visited = true;

  for(int i = 0; i < (*root)->children.size(); i++)
    dfs(&(*root)->children[i]);
}

bool check_path(node** root, map<int, node*> m)
{
  if(!*root) return true;

  dfs(root);

  for(map<int, node*>::iterator it = m.begin(); it != m.end(); ++it)
    if(it -> second -> visited == false) return false;
  return true;
}

int main()
{
  int a, b, k = 0, cont_root_nodes;
  bool compute = true, ans;

  while(compute)
  {
    map<int, node*> m;
    ans = true;
    while(scanf("%d %d",&a,&b) != EOF && a && b)
    {
      if(a == -1 && b == -1){ compute = false; break; }

      if(m.find(a) == m.end())
      {
        node* new_node = new node;
        new_node->visited = false;
        new_node->parents = 0;
        m[a] = new_node;
      }

      if(m.find(b) == m.end())
      {
        node* new_node = new node;
        new_node->visited = false;
        new_node->parents = 1;
        m[b] = new_node;
      }
      else
      {
        m[b]->parents++;
      }

      m[a]->children.push_back(m[b]);
    }

    cont_root_nodes = 0;
    node* root = NULL;
    for(map<int, node*>::iterator it = m.begin(); it != m.end(); ++it)
    {
      if(it -> second -> parents > 1) ans = false;
      if(it -> second -> parents == 0) { cont_root_nodes++; root = it->second; }
    }

    if(cont_root_nodes != 1 && m.size() > 0) ans = false;

    if(ans)
      ans = check_path(&root, m);

    if(compute)
    {
      if(ans)
        printf("Case %d is a tree.\n", ++k);
      else
        printf("Case %d is not a tree.\n", ++k);
    }

  }

  return 0;
}