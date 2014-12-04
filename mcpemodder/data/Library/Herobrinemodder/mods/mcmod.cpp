/* 
 This mod is a simple speed mod that overrides the symbol Player$$getWalkingSpeed and returns it to 2.0
 
 You can find mcpe's symbols by loading the decrypted binary file into IDA
 
 I'll explain every line of code in this file for you

 
 */

#include <substrate.h>
// This includes the substrate header file, so we can use MSHookFunction and MSFindSymbol. This is required by all mods


float (*old_Player$$getWalkingSpeed)();
// This defines the original Player$$getWalkingSpeed, just incase we need it



float Player$$getWalkingSpeed() {
// This is the declared function. You can add almost any code here, as long as it returns a float
    return 2.0; // This sets the player speed to 2.0. You can modify this to what even number you like, as long as it's decimal
}




MSInitialize {
// MSInitlize starts at runtime. We hook the function at this time
    MSHookFunction(((float*)MSFindSymbol(NULL, "__ZN6Player23getWalkingSpeedModifierEv")),(float*)Player$$getWalkingSpeed,(float**)&old_Player$$getWalkingSpeed);
    // Here we hook the function. You'll see MSHookSymbol using a weird string (__ZN6Player23getWalkingSpeedModifierEv). This is the mangled symbol. IDA can automatically demangle symbols, but you need the mangled version to hook the fuction. You'll see the 2 other parts, after the mangled symbols (Player$$getWalkingSpeed and old_Player$$getWalkingSpeed). You can name it whatever, but make sure it is the same name as the ones above (float Player$$getWalkingSpeed() and float (*old_Player$$getWalkingSpeed)()) else your code will fail to compile
    
    
}