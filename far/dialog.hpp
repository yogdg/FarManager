#ifndef __DIALOG_HPP__
#define __DIALOG_HPP__
/*
dialog.hpp

����� ������� Dialog.

�।�����祭 ��� �⮡ࠦ���� �������� ��������.
������� �ந������ �� ����� Modal.

*/

/* Revision: 1.02 23.07.2000 $ */

/*
Modify:
  23.07.2000 SVS
   + ��� ६�ப � ��室����� :-)
   + �㭪�� ��ࠡ�⪨ ������� (�� 㬮�砭��) - ����� ���� :-)
   ! ������� �맮� ���������
  18.07.2000 SVS
    + �㭪�� SelectFromComboBox ��� �롮� �� DI_COMBOBOX
  25.06.2000 SVS
    ! �����⮢�� Master Copy
    ! �뤥����� � ����⢥ ᠬ����⥫쭮�� �����
*/

class Dialog:public Modal
{
  private:
    struct DialogItem *Item;    // ���ᨢ ������⮢ �������
    int ItemCount;              // ������⢮ ������⮢ �������

    char OldConsoleTitle[512];  // �।��騩 ��������� ���᮫�
    int InitObjects;            // �������� ���樠����஢���?
    int CreateObjects;          // ��ꥪ�� (Edit,...) ᮧ����?
    int WarningStyle;           // TRUE - Warning Dialog Style
    int DialogTooLong;          //
    int PrevMacroMode;          // �।��騩 ०�� ����
    FARDIALOGPROC DlgProc;      // �㭪�� ��ࠡ�⪨ �������

  private:
    void DisplayObject();
    void DeleteDialogObjects();
    void ShowDialog();
    int ChangeFocus(int FocusPos,int Step,int SkipGroup);
    int IsEdit(int Type);
    void SelectFromEditHistory(Edit *EditLine,char *HistoryName);
    /* $ 18.07.2000 SVS
       + �㭪�� SelectFromComboBox ��� �롮� �� DI_COMBOBOX
    */
    void SelectFromComboBox(Edit *EditLine,struct FarListItem *HistoryName);
    /* SVS $ */
    void AddToEditHistory(char *AddStr,char *HistoryName);
    int ProcessHighlighting(int Key,int FocusPos,int Translate);

  public:
    Dialog(struct DialogItem *Item,int ItemCount,FARDIALOGPROC DlgProc=NULL);
    ~Dialog();

  public:
    int ProcessKey(int Key);
    int ProcessMouse(MOUSE_EVENT_RECORD *MouseEvent);
    void Show();
    void FastShow() {ShowDialog();}
    void InitDialogObjects();
    void GetDialogObjectsData();
    void SetWarningStyle(int Style) {WarningStyle=Style;};

    static void DataToItem(struct DialogData *Data,struct DialogItem *Item,
                           int Count);
    static int IsKeyHighlighted(char *Str,int Key,int Translate);
    /* $ 23.07.2000 SVS
       �㭪�� ��ࠡ�⪨ ������� (�� 㬮�砭��)
    */
    static long WINAPI DefDlgProc(HANDLE hDlg,int Msg,int Param1,long Param2);
    /* SVS $ */
};

#endif // __DIALOG_HPP__
