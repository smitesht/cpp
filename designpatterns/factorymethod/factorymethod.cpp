// factorymethod.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class IFile
{
public:
    virtual void printFile() = 0;
    virtual void readFile() = 0;
};

class PdfFile : public IFile
{
public:
    void printFile();
    void readFile();
};

void PdfFile::printFile()
{
    cout << "PdfFile::printFile" << endl;
}

void PdfFile::readFile()
{
    cout << "PdfFile::readFile" << endl;
}

class DocFile : public IFile
{
public:
    void printFile();
    void readFile();
};

void DocFile::printFile()
{
    cout << "DocFile::printFile" << endl;
}

void DocFile::readFile()
{
    cout << "DocFile::readFile" << endl;
}
class XlsFile : public IFile
{
public:
    void printFile();
    void readFile();
};

void XlsFile::printFile()
{
    cout << "XlsFile::printFile" << endl;
}

void XlsFile::readFile()
{
    cout << "XlsFile::readFile" << endl;
}

enum FileType {
    PDF = 0,
    DOC = 1,
    XLS = 2
};

class FileFactory
{
public:
    FileFactory();
	~FileFactory();

    static IFile* GetFile(FileType ft);

private:

};


IFile* FileFactory::GetFile(FileType ft)
{
    IFile* filetype = NULL;

    switch (ft)
    {
    case FileType::PDF:
        filetype = new PdfFile();
        break;
    case FileType::DOC:
        filetype = new DocFile();
        break;
    case FileType::XLS:
        filetype = new XlsFile();
        break;

    default:
        break;
    }

    return filetype;
}

int main()
{
    IFile* pdfFile = FileFactory::GetFile(FileType::PDF);
    pdfFile->printFile();
    pdfFile->readFile();

    IFile* docFile = FileFactory::GetFile(FileType::DOC);
    docFile->printFile();
    docFile->readFile();

    IFile* xlsFile = FileFactory::GetFile(FileType::XLS);
    xlsFile->printFile();
    xlsFile->readFile();
}

