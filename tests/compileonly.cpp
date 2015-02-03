#include "camp/config.hpp"
#include "camp/args.hpp"
#include "camp/type.hpp"
#include "camp/error.hpp"
#include "camp/detail/yesnotype.hpp"
#include "camp/detail/issmartpointer.hpp"
#include "camp/detail/rawtype.hpp"
#include "camp/detail/objecttraits.hpp"
#include "camp/detail/typeid.hpp"
#include "camp/detail/observernotifier.hpp"
#include "camp/detail/returntype.hpp"

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
