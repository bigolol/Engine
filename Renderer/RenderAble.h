#pragma once
class RenderAble
{
public:
	RenderAble();
	~RenderAble();
	virtual void render() = 0;
	virtual void cleanUp() = 0;
private:

public:

private:


};

