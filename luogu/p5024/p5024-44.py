MAXN = 100005
n = 0
m = 0
type = 0
cnt = 0
val = [MAXN]
head = [MAXN]
rest = [MAXN]
f = []
class Edge:
    def __init__(self,next=0,to=0):
        self.next = next
        self.to = to

def dfs(v,u):
    if vis[u] == 0 and vis == 0:
        return -1
    f[v][0] = 0
    f[v][1] = val[v]
    while true:
        i = head[v]
        y = e[i].to
        if y == u:  continue
        if dfs(y,v) < 0:    return -1
        f[v][0] += f[y][1]
        if vis[y] == 0:
            f[v][1] = f[v][1] + f[y][0]
            vis[v] = 1
        elif vis[y] == 1:
            f[v][1] = f[v][1]+ f[y][1]
        else:
            f[v][1] = min(f[v][1] + f[y][0],f[v][1] + f[y][1])
        i = e[i].next
    if vis[v] == 1:
        return f[v][1]
    elif vis[v] == 0:
        return f[v][0]
    else:   return min(f[v][0],f[v][1])


def trans(id):
    a = rest[id]['node1']
    b = rest[id]['node2']
    x = rest[id]['val1']
    y = rest[id]['val2']
    vis[a] = x
    vis[b] = y
e[MAXN] = Edge()

def add(u,v):
    e[cnt].to = v
    e[cnt].next = head[u]
    head[u] = cnt
    cnt += 1

if __name__ == '__main__':
    n = input()
    m = input()
    type = input()
    for i in range(n):
        val[i + 1] = input()
    for j in range(n - 1):
        a = input()
        b = input()
        add(a,b)
        add(b,a)
    x = 0
    y = 0
    for i in range(MAXN):
        rest[i+1] = {'node1': 0, 'val1': 0, 'node2': 0, 'val2': 0}
    for i in range(m):
        a = input()
        x = input()
        b = input()
        y = input()
        rest[i+1]['node1'] = a
        rest[i+1]['val1'] = x
        rest[i+1]['node2'] = b
        rest[i+1]['val2'] = y
    for i in range(m):
        tran(i+1)
        res = dfs(1,0)
        print(res)