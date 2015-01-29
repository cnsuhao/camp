namespace camp {

template <typename T>
T Error::prepare(T error, const std::string& file, int line, const std::string& function)
{
	error.location_ = file + " (" + str(line) + " ) - " + function;
	return error;
}

template <typename T>
std::string Error::str(T value)
{
	return boost::lexical_cast<std::string>(value);
}

}
