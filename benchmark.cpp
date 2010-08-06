#include <sys/time.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "sparse_vector.h"

using namespace std;

#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define REP(i,n) FOR(i,0,n)
#define sz size()

/**
 * For array with 1 million entries do the following in a loop: initialize some
 * values in it, then clear all values. Try vector and sparse_vector.
 */
int main() {
    timeval st,fn;
    int mtime;
    int N = 1000000;
    int LOOP = 1000;

    // usual vector
    gettimeofday(&st, 0);
    vector<double> a(N);
    REP(i,LOOP) {
        for (int j=0; j<a.sz; j+=100) a[j]=j;
        REP(j,a.sz) a[j]=0;
    }
    gettimeofday(&fn, 0);
    mtime = (fn.tv_sec-st.tv_sec)*1000 + (fn.tv_usec-st.tv_usec)/1000;
    printf("VECTOR:\t\t%ds %dms\n", mtime/1000, mtime%1000);

    // sparse vector
    gettimeofday(&st, 0);
    sparse_vector<double> b(1000000,-1);
    REP(i,1000) {
        for (int j=0; j<b.sz; j+=100) b[j]=j;
        b.clear();
    }
    gettimeofday(&fn, 0);
    mtime = (fn.tv_sec-st.tv_sec)*1000 + (fn.tv_usec-st.tv_usec)/1000;
    printf("SPARSE VECTOR:\t%ds %dms\n", mtime/1000, mtime%1000);
}

