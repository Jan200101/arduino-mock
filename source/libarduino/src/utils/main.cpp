#ifdef STATIC
extern void setup();
extern void loop();
#else
void setup() {}
void loop() {}
#endif

int main()
{
    setup();

    while (true) loop();
}