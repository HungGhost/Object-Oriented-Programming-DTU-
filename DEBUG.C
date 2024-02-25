// Become familiar wih C syntax
// Learn to debug buggy code
#include <cs50.h>
#include <stdio.h>
int main(void)
{
    // Ask for your name and where live
    string name = get_string("Ai La Nguoi Dep Trai Nhat? ");
    string location = get_string("Va May Song O Dau? ");
    // Say hello
    printf("Hello, %s, from %s!", name, location);
}
