#include "Serializer.hpp"

/**
 * reinterpret_cast ables to convert and unconvert
 * 	from one data type to another without losing info
 */

uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
