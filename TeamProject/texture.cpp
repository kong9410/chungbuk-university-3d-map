/*********************************************************************************************************************

* �ۼ��� : ����ö, ����ȣ

* ���ϸ� : texture.cpp

* ���� : �ؽ��� �ҷ����� �Լ� ����

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


	// RGB�� ������ �ٲ۴�.

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