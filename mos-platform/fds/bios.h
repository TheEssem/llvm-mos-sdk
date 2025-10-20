#ifndef _BIOS_H_
#define _BIOS_H_

#ifdef __cplusplus
extern "C" {
#endif

struct fds_disk_id {
  unsigned char licensee;
  char name[4];
  char version;
  char side_num;
  char disk_num;
  char disk_type;
  char _unk;
  char num_files;
};

struct fds_file_header {
  char id;
  char name[8];
  char *dest;
  unsigned int size;
  char type;
  char *source;
  char source_type;
};

#define FDS_XFR_MODE_COPY 0
#define FDS_XFR_MODE_FILL 1

#define FDS_XFR_INC_1 0
#define FDS_XFR_INC_32 1

struct fds_vram_transfer {
  unsigned int address;
  unsigned int length : 6;
  unsigned int mode : 1;
  unsigned int increment : 1;
};

#define FDS_OBJ_NORMAL 0x00
#define FDS_OBJ_SKIP 0x01
#define FDS_OBJ_HIDE 0x80

struct fds_object {
  unsigned char render_flag;
  unsigned char y;
  unsigned char y_fractional;
  unsigned char x;
  unsigned char x_fractional;
  unsigned char anim_frame;
  unsigned int tile_arrange_ptr;
  struct {
    unsigned int flip_y : 1;
    unsigned int _unused : 3;
    unsigned int flip_x : 1;
  } flags;
  unsigned char palette;
  struct {
    unsigned int width : 4;
    unsigned int height : 4;
  } size;
  unsigned char oam_idx;
};

struct fds_trans_pads {
  unsigned char trans[2];
  unsigned char data[2];
};

struct fds_trans_exp_pads {
  unsigned char trans[4];
  unsigned char data[4];
};

struct keyboard_data {
  char clr_home : 1;
  char up : 1;
  char right : 1;
  char left : 1;
  char down : 1;
  char space : 1;
  char del : 1;
  char ins : 1;

  char f1 : 1;
  char esc : 1;
  char q : 1;
  char ctr : 1;
  char lshift : 1;
  char grph : 1;
  char one : 1;
  char two : 1;

  char f2 : 1;
  char w : 1;
  char s : 1;
  char a : 1;
  char x : 1;
  char z : 1;
  char e : 1;
  char three : 1;

  char f3 : 1;
  char t : 1;
  char r : 1;
  char d : 1;
  char f : 1;
  char c : 1;
  char five : 1;
  char four : 1;

  char f4 : 1;
  char y : 1;
  char g : 1;
  char h : 1;
  char b : 1;
  char v : 1;
  char seven : 1;
  char six : 1;

  char f5 : 1;
  char i : 1;
  char u : 1;
  char j : 1;
  char m : 1;
  char n : 1;
  char nine : 1;
  char eight : 1;

  char f6 : 1;
  char o : 1;
  char l : 1;
  char k : 1;
  char period : 1;
  char comma : 1;
  char p : 1;
  char zero : 1;

  char f7 : 1;
  char at : 1;
  char colon : 1;
  char semicolon : 1;
  char underscore : 1;
  char slash : 1;
  char dash : 1;
  char caret : 1;

  char f8 : 1;
  char ret : 1;
  char lbracket : 1;
  char rbracket : 1;
  char kana : 1;
  char rshift : 1;
  char yen : 1;
  char stop : 1;
};

char fds_LoadFiles (struct fds_disk_id *disk_id, char *file_ids, char *loaded) __attribute__((leaf));
char fds_AppendFile (struct fds_disk_id *disk_id, struct fds_file_header *file_header) __attribute__((leaf));
char fds_WriteFile (struct fds_disk_id *disk_id, struct fds_file_header *file_header, char file_num) __attribute__((leaf));
char fds_CheckFileCount (struct fds_disk_id *disk_id, char count) __attribute__((leaf));
char fds_AdjustFileCount (struct fds_disk_id *disk_id, char count) __attribute__((leaf));
char fds_SetFileCount1 (struct fds_disk_id *disk_id, char count) __attribute__((leaf));
char fds_SetFileCount (struct fds_disk_id *disk_id, char count) __attribute__((leaf));
char fds_GetDiskInfo (struct fds_disk_id *disk_id) __attribute__((leaf));

char fds_CheckDiskHeader (char string[10]);
unsigned char fds_GetNumFiles (void);
void fds_SetNumFiles (unsigned char num);
char fds_FileMatchTest (char *ids);
void fds_SkipFiles (unsigned char num);

void fds_Delay131 (void);
void fds_Delayms (char delay) __attribute__((leaf));

void fds_DisPFObj (void);
void fds_EnPFObj (void);
void fds_DisObj (void);
void fds_EnObj (void);
void fds_DisPF (void);
void fds_EnPF (void);

void fds_VINTWait (void);

void *fds_FetchDirectPtr (void);

unsigned fds_Pixel2NamConv (unsigned char y, unsigned char x);

void fds_SpriteDMA (void);

struct fds_trans_pads *fds_ReadDownPads(void);
struct fds_trans_pads *fds_ReadOrDownPads(void);
struct fds_trans_pads *fds_ReadDownVerifyPads(void);
struct fds_trans_pads *fds_ReadOrDownVerifyPads(void);
struct fds_trans_exp_pads *fds_ReadDownExpPads(void);

void fds_VRAMFill (char tile_row, char value, char rows_attr) __attribute__((leaf));
void fds_MemFill (char value, char start, char end) __attribute__((leaf));

char fds_ReadKeyboard(struct keyboard_data *data);

void fds_UploadObject (struct fds_object *obj);

#ifdef __cplusplus
}
#endif

#endif
