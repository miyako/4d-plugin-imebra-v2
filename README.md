# 4d-plugin-imebra-v2
Read DICOM files.

Based on [libimebra 4.0.7.1](https://imebra.com)

###Platform

| carbon | cocoa | win32 | win64 |
|:------:|:-----:|:---------:|:---------:|
|🆗|🆗|🚫|🚫|

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
