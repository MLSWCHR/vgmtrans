#pragma once
#include "VGMInstrSet.h"
#include "VGMSampColl.h"
#include "VGMRgn.h"
#include "GraphResSnesFormat.h"

// ********************
// GraphResSnesInstrSet
// ********************

class GraphResSnesInstrSet :
	public VGMInstrSet
{
public:
	GraphResSnesInstrSet(RawFile* file, GraphResSnesVersion ver, uint32_t spcDirAddr, const std::map<uint8_t, uint16_t> & instrADSRHints, const std::wstring & name = L"GraphResSnesInstrSet");
	virtual ~GraphResSnesInstrSet(void);

	virtual bool GetHeaderInfo();
	virtual bool GetInstrPointers();

	GraphResSnesVersion version;

protected:
	uint32_t spcDirAddr;
	std::map<uint8_t, uint16_t> instrADSRHints;
	std::vector<uint8_t> usedSRCNs;
};

// *****************
// GraphResSnesInstr
// *****************

class GraphResSnesInstr
	: public VGMInstr
{
public:
	GraphResSnesInstr(VGMInstrSet* instrSet, GraphResSnesVersion ver, uint8_t srcn, uint32_t spcDirAddr, uint16_t adsr = 0x8ff0, const std::wstring& name = L"GraphResSnesInstr");
	virtual ~GraphResSnesInstr(void);

	virtual bool LoadInstr();

	GraphResSnesVersion version;

protected:
	uint32_t spcDirAddr;
	int8_t transpose;
	int16_t pitch;
	uint16_t adsr;
};

// ***************
// GraphResSnesRgn
// ***************

class GraphResSnesRgn
	: public VGMRgn
{
public:
	GraphResSnesRgn(GraphResSnesInstr* instr, GraphResSnesVersion ver, uint8_t srcn, uint32_t spcDirAddr, uint16_t adsr = 0x8ff0);
	virtual ~GraphResSnesRgn(void);

	virtual bool LoadRgn();

	GraphResSnesVersion version;

protected:
	int8_t transpose;
	int16_t pitch;
	uint16_t adsr;
};
