#include <iostream>
using namespace std;

int main()
{
char32_t a[8] = U" AGONY";
char32_t b[8] = U"";

char32_t *n_b = &b[0];
char32_t *k_a = &a[5];
char32_t *n_a = &a[0];
//cout«*k_a«endl;
asm(
"mov %[k_a], %%rax \n\t"
"mov %[n_b], %%rbx \n\t"
"start: \n\t"
"push (%%rax) \n\t"
"pop (%%rbx) \n\t"
"add $-4, %%rax \n\t"
"add $4, %%rbx \n\t"
"cmp %[n_a], %%rax \n\t"
"jne start \n\t"
//"mov %[n_b], %%rbx \n\t"
"end_asm: \n\t"
:
: [n_a]"m"(n_a),
[k_a]"m"(k_a),
[n_b]"m"(n_b)
: "%rax", "%rbx"
);

for (int i=0; i<5; i++)
{
cout<<b[i]<< " ";
}
cout<<endl;
for (int i=0; i<5; i++)
{
cout<<a[i]<< " ";
}
cout<<endl;
return 0;
}
