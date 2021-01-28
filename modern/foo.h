#ifdef __cpp
extern "C" {
#endif

int add(int x, int y);

#ifdef __cpp
}
#endif

int add(int x, int y) { return x + y; }