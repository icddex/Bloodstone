#include "DexCoreObject.h"

namespace Dex
{
	CoreObject::CoreObject(const String& c_name, WorkPriority wp, bool fw)
		: mObjectName(c_name)
	{
		mWorkPriority = wp;
		mFreeWork = fw;
		mOutFileStream = nullptr;
	}

	CoreObject::~CoreObject()
	{
	}

	void CoreObject::SetOutFileStream(OFStream* os)
	{
		if (mOutFileStream != nullptr) {
			char* ms = "Go to/n";
			mOutFileStream->write(ms, sizeof(ms));
		}
		
		mOutFileStream = os;
	}

	void CoreObject::DrawLine(const String& text, const MessageTypes& mt)
	{
		if (mOutFileStream != nullptr) {
			char* mt_c = "";
			switch (mt)
			{
			case MessageTypes::NORMAL:
				mt_c = "normal";
				break;
			case MessageTypes::WARNING:
				mt_c = "warning";
				break;
			case MessageTypes::EZ_ERROR:
				mt_c = "error";
				break;
			}

			*mOutFileStream << mt_c << "--" << mObjectName << "--" << text.c_str() << std::endl;
			mOutFileStream->flush();
		}
	}

	const String& CoreObject::GetName()
	{
		return mObjectName;
	}

	WorkPriority CoreObject::GetWP()
	{
		return mWorkPriority;
	}
}