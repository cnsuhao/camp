#include "camp/config.hpp"
#include "camp/args.hpp"
#include "camp/type.hpp"
#include "camp/error.hpp"

void foo()
{
	printf("%s\n", BOOST_CURRENT_FUNCTION);
}

int main()
{
	foo();
	printf("%s\n", BOOST_CURRENT_FUNCTION);
	return 0;
}
