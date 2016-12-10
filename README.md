# 4d-plugin-imebra-v2
Read DICOM files.

Based on [libimebra 4.0.7.1](https://imebra.com)

###Platform

| carbon | cocoa | win32 | win64 |
|:------:|:-----:|:---------:|:---------:|
|🆗|🆗|🆗|🆗|

###Version

<img src="https://cloud.githubusercontent.com/assets/1725068/18940649/21945000-8645-11e6-86ed-4a0f800e5a73.png" width="32" height="32" /> <img src="https://cloud.githubusercontent.com/assets/1725068/18940648/2192ddba-8645-11e6-864d-6d5692d55717.png" width="32" height="32" />

###Syntax

```
tags:=Imebra_Get_images (dicom;images)
```

param|type|description
------------|------|----
dicom|BLOB|DICOM data
images|ARRAY PICTURE|rendered images (PNG format)
tags|TEXT|JSON representation of all tags

Example result for ``images``

![1](https://cloud.githubusercontent.com/assets/1725068/20998248/db2a3e4e-bd4f-11e6-80c6-137af92602f4.png)

Example result for ``tags``

```json
[
	{
		"type" : "UL",
		"id" : 0,
		"group" : 8,
		"order" : 0,
		"index" : 0,
		"value" : "286"
	},
	{
		"type" : "CS",
		"id" : 8,
		"group" : 8,
		"order" : 0,
		"index" : 0,
		"value" : "ORIGINAL PRIMARY"
	},
	{
		"type" : "DA",
		"id" : 18,
		"group" : 8,
		"order" : 0,
		"index" : 0,
		"value" : "1995.07.20"
	},
	{
		"type" : "TM",
		"id" : 19,
		"group" : 8,
		"order" : 0,
		"index" : 0,
		"value" : "11:22:07"
	},
	{
		"type" : "UI",
		"id" : 22,
		"group" : 8,
		"order" : 0,
		"index" : 0,
		"value" : "1.2.840.10008.5.1.4.1.1.1"
	},
	{
		"type" : "UI",
		"id" : 24,
		"group" : 8,
		"order" : 0,
		"index" : 0,
		"value" : "1.2.392.200036.9125.0.19950720112207"
	},
	{
		"type" : "DA",
		"id" : 34,
		"group" : 8,
		"order" : 0,
		"index" : 0,
		"value" : "1993.02.24"
	},
	{
		"type" : "TM",
		"id" : 50,
		"group" : 8,
		"order" : 0,
		"index" : 0,
		"value" : "17:58:00"
	},
	{
		"type" : "SH",
		"id" : 80,
		"group" : 8,
		"order" : 0,
		"index" : 0,
		"value" : "FUJI95714"
	},
	{
		"type" : "CS",
		"id" : 96,
		"group" : 8,
		"order" : 0,
		"index" : 0,
		"value" : "CR"
	},
	{
		"type" : "LO",
		"id" : 112,
		"group" : 8,
		"order" : 0,
		"index" : 0,
		"value" : "FUJI PHOTO FILM CO. LTD."
	},
	{
		"type" : "LO",
		"id" : 128,
		"group" : 8,
		"order" : 0,
		"index" : 0,
		"value" : "FUJI PHOTO FILM CO.,"
	},
	{
		"type" : "LO",
		"id" : 4160,
		"group" : 8,
		"order" : 0,
		"index" : 0,
		"value" : "!!!!!!!!"
	},
	{
		"type" : "LO",
		"id" : 4240,
		"group" : 8,
		"order" : 0,
		"index" : 0,
		"value" : "9000"
	},
	{
		"type" : "UL",
		"id" : 0,
		"group" : 16,
		"order" : 0,
		"index" : 0,
		"value" : "18"
	},
	{
		"type" : "PN",
		"id" : 16,
		"group" : 16,
		"order" : 0,
		"index" : 0,
		"value" : "Anonymized"
	},
	{
		"type" : "UL",
		"id" : 0,
		"group" : 24,
		"order" : 0,
		"index" : 0,
		"value" : "140"
	},
	{
		"type" : "CS",
		"id" : 21,
		"group" : 24,
		"order" : 0,
		"index" : 0,
		"value" : "CHEST"
	},
	{
		"type" : "DS",
		"id" : 4176,
		"group" : 24,
		"order" : 0,
		"index" : 0,
		"value" : "0.2"
	},
	{
		"type" : "SH",
		"id" : 4704,
		"group" : 24,
		"order" : 0,
		"index" : 0,
		"value" : "ST"
	},
	{
		"type" : "LO",
		"id" : 4705,
		"group" : 24,
		"order" : 0,
		"index" : 0,
		"value" : "5"
	},
	{
		"type" : "LO",
		"id" : 5120,
		"group" : 24,
		"order" : 0,
		"index" : 0,
		"value" : "[CHEST,GENERAL     ]"
	},
	{
		"type" : "LO",
		"id" : 5121,
		"group" : 24,
		"order" : 0,
		"index" : 0,
		"value" : "00"
	},
	{
		"type" : "CS",
		"id" : 5122,
		"group" : 24,
		"order" : 0,
		"index" : 0,
		"value" : "PORTRAIT"
	},
	{
		"type" : "CS",
		"id" : 5123,
		"group" : 24,
		"order" : 0,
		"index" : 0,
		"value" : "35CMX35CM"
	},
	{
		"type" : "CS",
		"id" : 20737,
		"group" : 24,
		"order" : 0,
		"index" : 0,
		"value" : "PA"
	},
	{
		"type" : "DS",
		"id" : 24576,
		"group" : 24,
		"order" : 0,
		"index" : 0,
		"value" : "357"
	},
	{
		"type" : "UL",
		"id" : 0,
		"group" : 32,
		"order" : 0,
		"index" : 0,
		"value" : "102"
	},
	{
		"type" : "UI",
		"id" : 13,
		"group" : 32,
		"order" : 0,
		"index" : 0,
		"value" : "1.2.392.200036.9125.0.199302241758.16"
	},
	{
		"type" : "UI",
		"id" : 14,
		"group" : 32,
		"order" : 0,
		"index" : 0,
		"value" : "1.2.392.200036.9125.0.199302241758.16"
	},
	{
		"type" : "IS",
		"id" : 19,
		"group" : 32,
		"order" : 0,
		"index" : 0,
		"value" : "16"
	},
	{
		"type" : "UL",
		"id" : 0,
		"group" : 40,
		"order" : 0,
		"index" : 0,
		"value" : "124"
	},
	{
		"type" : "US",
		"id" : 2,
		"group" : 40,
		"order" : 0,
		"index" : 0,
		"value" : "1"
	},
	{
		"type" : "CS",
		"id" : 4,
		"group" : 40,
		"order" : 0,
		"index" : 0,
		"value" : "MONOCHROME1"
	},
	{
		"type" : "US",
		"id" : 16,
		"group" : 40,
		"order" : 0,
		"index" : 0,
		"value" : "440"
	},
	{
		"type" : "US",
		"id" : 17,
		"group" : 40,
		"order" : 0,
		"index" : 0,
		"value" : "440"
	},
	{
		"type" : "IS",
		"id" : 52,
		"group" : 40,
		"order" : 0,
		"index" : 0,
		"value" : "01"
	},
	{
		"type" : "US",
		"id" : 256,
		"group" : 40,
		"order" : 0,
		"index" : 0,
		"value" : "16"
	},
	{
		"type" : "US",
		"id" : 257,
		"group" : 40,
		"order" : 0,
		"index" : 0,
		"value" : "10"
	},
	{
		"type" : "US",
		"id" : 258,
		"group" : 40,
		"order" : 0,
		"index" : 0,
		"value" : "9"
	},
	{
		"type" : "US",
		"id" : 259,
		"group" : 40,
		"order" : 0,
		"index" : 0,
		"value" : "0"
	},
	{
		"type" : "DS",
		"id" : 4176,
		"group" : 40,
		"order" : 0,
		"index" : 0,
		"value" : "550"
	},
	{
		"type" : "DS",
		"id" : 4177,
		"group" : 40,
		"order" : 0,
		"index" : 0,
		"value" : "1024"
	},
	{
		"type" : "UL",
		"id" : 0,
		"group" : 8208,
		"order" : 0,
		"index" : 0,
		"value" : "14"
	},
	{
		"type" : "CS",
		"id" : 256,
		"group" : 8208,
		"order" : 0,
		"index" : 0,
		"value" : "BLACK"
	},
	{
		"type" : "UL",
		"id" : 0,
		"group" : 32736,
		"order" : 0,
		"index" : 0,
		"value" : "387208"
	},
	{
		"type" : "OB",
		"id" : 16,
		"group" : 32736,
		"order" : 0,
		"index" : 0,
		"value" : "0"
	}
]
```
