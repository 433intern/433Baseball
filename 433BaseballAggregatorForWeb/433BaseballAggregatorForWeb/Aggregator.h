#pragma once

class CAggregator
{
	CAggregator();
public:
	static CAggregator &GetInstance();
	~CAggregator();
};

