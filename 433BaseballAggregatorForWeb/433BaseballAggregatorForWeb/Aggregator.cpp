#include "stdafx.h"

CAggregator::CAggregator()
{
}

CAggregator::~CAggregator()
{
}

CAggregator &CAggregator::GetInstance()
{
	static CAggregator aggregator;
	return aggregator;
}
