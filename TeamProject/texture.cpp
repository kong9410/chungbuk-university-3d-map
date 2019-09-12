/*********************************************************************************************************************

* 작성자 : 공민철, 최진호

* 파일명 : texture.cpp

* 설명 : 텍스쳐 불러오는 함수 정의

**********************************************************************************************************************/

#include"Texture.h"
#include<iostream>


GLubyte *LoadBmp(const char *Path, int *Width, int *Height)

{
	HANDLE hFile;
	DWORD FileSize, dwRead;
	BITMAPFILEHEADER *fh = NULL;
	BITMAPINFOHEADER *ih;
	BYTE *pRaster;

	hFile = CreateFileA(Path, GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		printf("FAIL LOAD IMAGE : %s\n", Path);
		return NULL;
	}

	FileSize = GetFileSize(hFile, NULL);
	fh = (BITMAPFILEHEADER *)malloc(FileSize);
	ReadFile(hFile, fh, FileSize, &dwRead, NULL);
	CloseHandle(hFile);

	int len = FileSize - fh->bfOffBits;
	pRaster = (GLubyte *)malloc(len);
	memcpy(pRaster, (BYTE *)fh + fh->bfOffBits, len);


	// RGB로 순서를 바꾼다.

	for (BYTE *p = pRaster; p < pRaster + len - 3; p += 3) {
		BYTE b = *p;
		*p = *(p + 2);
		*(p + 2) = b;
	}

	ih = (BITMAPINFOHEADER *)((PBYTE)fh + sizeof(BITMAPFILEHEADER));
	*Width = ih->biWidth;
	*Height = ih->biHeight;

	free(fh);
	return pRaster;
}