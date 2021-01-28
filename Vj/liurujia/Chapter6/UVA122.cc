#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define maxn 1001000

using namespace std;

struct Node {
  bool have_value;
  int v;
  Node *left, *right;
  Node() : have_value(false), left(NULL), right(NULL) {}
};

int v;
bool failed;
char s[maxn];

Node *root;
Node *newnode() { return new Node(); }

inline void remove_tree(Node *p) {
  if (p == NULL) {
    return;
  }
  remove_tree(p->left);
  remove_tree(p->right);
  delete p;
}

inline bool BFS(vector<int> &ans) {
  ans.clear();
  queue<Node *> Q;
  Q.push(root);
  while (!Q.empty()) {
    Node *u = Q.front();
    Q.pop();
    if (!u->have_value) {
      return false;
    }
    ans.push_back(u->v);
    if (u->left != NULL) {
      Q.push(u->left);
    }
    if (u->right != NULL) {
      Q.push(u->right);
    }
  }
  return true;
}
inline void add_Node(int v, char *s) {
  int n = strlen(s);
  Node *u = root;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'L') {
      if (u->left == NULL) {
        u->left = newnode();
      }
      u = u->left;
    }
    if (s[i] == 'R') {
      if (u->right == NULL) {
        u->right = newnode();
      }
      u = u->right;
    }
  }
  if (u->have_value) {
    failed = true;
  }
  u->v = v;
  u->have_value = true;
}

inline bool read_input() {
  failed = false;
  remove_tree(root);
  root = newnode();
  for (;;) {
    if (scanf("%s", s) != 1) {
      return false;
    }
    if (strcmp(s, "()") == 0) {
      break;
    }
    sscanf(&s[1], "%d", &v);
    add_Node(v, strchr(s, ',') + 1);
  }
  return true;
}

int main() {
  // freopen("data.in","r",stdin);
  vector<int> ans;
  while (read_input()) {
    if (failed || !BFS(ans)) {
      printf("not complete");
    } else {
      for (vector<int>::iterator t = ans.begin(); t != ans.end(); t++) {
        if (t != ans.end() - 1) {
          printf("%d ", *t);
        } else {
          printf("%d", *t);
        }
      }
    }
    printf("\n");
  }
  return 0;
}