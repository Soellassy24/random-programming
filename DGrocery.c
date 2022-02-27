#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct { 
	char barang[30];
	double harga;
} kategori;

struct{
	char nama [100], user[100], pass[100];
} penjual;

struct{
	char nama [100], user[100], pass[100];
} pembeli;
		
void login_admin(int a);
void login_pembeli(int a);
void login_penjual(int a);
void user_admin();
void edit_kategori();
void edit_penjual();
void edit_pembeli();
void user_penjual();
void user_pembeli();
void menu_troli();

int i, n, pil, ulang, check, jumlah, temu=0;
//long int offset_byte;
char cari[50], cari_kategori[20], daftar_kategori[50], user_in[20], pass_in[20];

void registrasi_akun(){			//program default untuk regitrasi akun baru untuk pembeli atau penjual
	printf(" Daftar Akun Baru sebagai : \n");
	printf(" 1. Penjual Baru\n");
	printf(" 2. Pembeli Baru\n");
	printf("\n 3. Kembali ke halaman sebelumnya\n");
	printf("\n===================\n");
	printf("Masukkan Pilihan Anda : "); scanf("%d", &pil);
	switch(pil){
		case 1 : {
			system("cls");
			FILE *file_akun_penjual;
			file_akun_penjual = fopen("data penjual.dat", "ab");
			getchar();
			printf("=====   SELAMAT DATANG PENJUAL BARU   ====\n");
			printf("Silahkan Lengkapi data berikut...\n");
			printf("\n");
			printf("   Nama Lengkap Penjual : "); gets(penjual.nama);
			printf("   Buat Username : "); gets(penjual.user);
			printf("   Buat Password : "); gets(penjual.pass);
			fwrite(&penjual, sizeof(penjual), 1, file_akun_penjual);
			fclose(file_akun_penjual);
			printf("\n\n- Akun Telah Terdaftar untuk Diverifikasi -");
			break;
		}
		case 2 : {
			system("cls");
			FILE *file_akun_pembeli;
			file_akun_pembeli = fopen("data pembeli.dat", "ab");
			getchar();
			printf("=====   SELAMAT DATANG PEMBELI BARU   ====\n");
			printf("Silahkan Lengkapi data berikut...\n");
			printf("\n");
			printf("   Nama Lengkap Pembeli : "); gets(pembeli.nama);
			printf("   Buat Username : "); gets(pembeli.user);
			printf("   Buat Password : "); gets(pembeli.pass);
			fwrite(&pembeli, sizeof(pembeli), 1, file_akun_pembeli);
			fclose(file_akun_pembeli);
			printf("\n\n   - Akun Telah Terdaftar -");
			break;
		}
		case 3:
			system("cls"); main(); break;
		default : printf("Opsi Tidak tersedia\n");
	}
	choice:
	printf("\n=========================================");
	printf("\n\n-Ketik 1 untuk Kembali ke halaman Sebelumnya\n");
	printf("Opsi Anda : "); scanf("%d", &ulang);
    switch(ulang){
    	case 1: system("cls"); main(); break;
    	default: system("cls");
    		printf("\t===  Program Anda Tidak Tersedia..  ==="); sleep(2); system("cls");
    		goto choice;
    		break;
	}
}


void list_kategori(){
	system("cls");
	printf(" == List Kategori Barang ==\n\n");
	FILE *file_kategori;
	file_kategori = fopen("list kategori.txt", "r");
	while (fgets(daftar_kategori, sizeof(daftar_kategori), file_kategori) != NULL)
	printf("----------\n");
	printf(" - %s\n",daftar_kategori);
	printf("----------\n");
	fclose (file_kategori);
	printf("      - End of List -\n");
}

void list_barang_kategori(char a[50]){
	system("cls");
	FILE*file_kategori;
	file_kategori = fopen(("%s", a),"rb");
	printf("== List Barang Kategori : %s ==\n\n", a);
	i=0;
	while(fread(&kategori,sizeof(kategori),1, file_kategori)==1){
	    i++;
	    printf("%d. Nama Barang : %s\n", i, kategori.barang);
	    printf("   Harga : Rp. %.2f\n", kategori.harga);
	    printf("\n==========\n");
	}
	printf("      - End of List -\n\n");
	fclose (file_kategori);
}

void check_password_penjual(){		//program check akun password penjual
	FILE *file_akun_penjual_verified; 
	file_akun_penjual_verified = fopen("data penjual terverifikasi.dat", "rb"); 
	fscanf(file_akun_penjual_verified,"%s",penjual.pass); 
	fclose(file_akun_penjual_verified); 
}

void check_username_penjual(){		//program check akun username penjual
	FILE *file_akun_penjual_verified; 
	file_akun_penjual_verified = fopen("data penjual terverifikasi.dat", "rb"); 
	fscanf(file_akun_penjual_verified,"%s",penjual.user); 
	fclose(file_akun_penjual_verified); 
}

void check_password_pembeli(){		//program check akun password pembeli
	FILE *file_akun_pembeli;
	file_akun_pembeli = fopen("data pembeli.dat", "rb");
	fscanf(file_akun_pembeli,"%s",pembeli.pass);
	fclose(file_akun_pembeli);
}

void check_username_pembeli(){		//program check akun username penjual
	FILE *file_akun_pembeli; 
	file_akun_pembeli = fopen("data pembeli.dat", "rb"); 
	fscanf(file_akun_pembeli,"%s",pembeli.user); 
	fclose(file_akun_pembeli); 
}

void list_kategori_admin(){		//program admin untuk melihat daftar kategori
	printf(" == List Kategori barang ==\n\n");
	FILE *file_kategori;
	file_kategori = fopen("list kategori.txt", "r");
	while (fgets(daftar_kategori, sizeof(daftar_kategori), file_kategori) != NULL)
	printf("----------\n");
	printf(" - %s\n",daftar_kategori);
	printf("----------\n");
	fclose (file_kategori);
	printf("      - End of List -");
	printf("\n\n=========================================");
	printf("\n-Ketik 1 untuk Logout (kembali ke Menu Utama)");
	printf("\n-Ketik 2 untuk Kembali ke halaman Sebelumnya\n");
	printf("Opsi Anda : "); scanf("%d", &ulang);
    switch(ulang){
    	case 1: system("cls"); main(); break;
    	case 2: system("cls"); edit_kategori(); break;
    	default: system("cls");
    		printf("Pilihan yang Anda Masukkan Tidak Tersedia\n"); 
			sleep(2); system("cls"); edit_kategori();
    		break;
	}
}

void tambah_kategori_admin(){		//program admin untuk menambah daftar kategori
	system("cls");
	printf("    == Tambah Kategori ==\n\n");
	FILE *file_kategori;
	file_kategori = fopen("list kategori.txt", "r");
	while (fgets(daftar_kategori, sizeof(daftar_kategori), file_kategori) != NULL)
	printf("----------\n");
	printf(" - %s\n",daftar_kategori);
	printf("----------\n");
	fclose (file_kategori);
	printf("      - End of List -\n");
	
	fflush(stdin);
	printf("\nTulis Nama Kategori Baru Dengan Format (<NAMA KATEGORI>.dat) !CAPSLOCK : "); gets(daftar_kategori);
	FILE *file_kategori_baru;
	file_kategori_baru = fopen("list kategori.txt","a");
	fprintf(file_kategori_baru, "%s\n", daftar_kategori);
	fclose (file_kategori_baru);
	
	file_kategori = fopen(("%s.dat", daftar_kategori),"wb");
	fclose(file_kategori);

	printf("\n\n=========================================");
	printf("\n\n-Ketik 1 untuk Logout (kembali ke Menu Utama)");
	printf("\n-Ketik 2 untuk Kembali ke halaman Sebelumnya\n");
	printf("Opsi Anda : "); scanf("%d", &ulang);
    switch(ulang){
    	case 1: system("cls"); main(); break;
    	case 2: system("cls"); edit_kategori(); break;
    	default: system("cls");
    		printf("Pilihan yang Anda Masukkan Tidak Tersedia\n"); 
			sleep(2); system("cls"); edit_kategori();
    		break;
	}
}

void edit_kategori(){	//program admin untuk memilih fitur admin-kategori
	system("cls");
	printf("=====   Menu Admin   =====\n");
	printf("\n 1. Melihat List Kategori\n");
	printf(" 2. Menambah List Kategori\n");
	printf("\n\n 3. Kembali ke Halaman Sebelumnya");
	printf("\n 4. Log out directly");
	printf("\n\n=========================================");
	printf("\n\nMasukkan Pilihan Admin : "); scanf("%d", &pil);
	switch(pil){
		case 1: system("cls"); list_kategori_admin(); break;
		case 2: system("cls"); tambah_kategori_admin(); break;
		case 3: system("cls"); user_admin(); break;
		default: break;
	}
	
	printf("\n\n=========================================");
	printf("\n\n-Ketik 1 untuk Logout (kembali ke Menu Utama)");
	printf("\n-Ketik 2 untuk Kembali ke halaman Sebelumnya\n");
	printf("Opsi Anda : "); scanf("%d", &ulang);
    switch(ulang){
    	case 1: system("cls"); main(); break;
    	case 2: system("cls"); edit_kategori(); break;
    	default: system("cls");
    		printf("Pilihan yang Anda Masukkan Tidak Tersedia\n"); 
			sleep(2); system("cls"); edit_kategori();
    		break;
	}
}

void list_penjual_admin(){	//program admin untuk melihat daftar akun penejual yang belum terverifikasi
	system("cls");
	FILE *file_akun_penjual;
	file_akun_penjual = fopen("data penjual.dat", "rb");
	printf(" List Akun Penjual yang Belum Diverifikasi:\n");
	printf("----------\n\n");
	while(fread(&penjual, sizeof(penjual), 1, file_akun_penjual) == 1){
		printf(" Nama : %s\n", penjual.nama);
		printf(" Username : %s\n", penjual.user);
		printf(" Password : %s\n", penjual.pass);
		printf("===================\n");
		printf("\n");
	}
	fclose(file_akun_penjual);
	printf("\n\n=========================================");
	printf("\n\n-Ketik 1 untuk Logout (kembali ke Menu Utama)");
	printf("\n-Ketik 2 untuk Kembali ke halaman Sebelumnya\n");
	printf("Opsi Anda : "); scanf("%d", &ulang);
    switch(ulang){
    	case 1: system("cls"); main(); break;
    	case 2: system("cls"); edit_penjual(); break;
    	default: system("cls");
    		printf("Pilihan yang Anda Masukkan Tidak Tersedia\n"); 
			sleep(2); system("cls"); edit_penjual();
    		break;
	}
}

void verifikasi_penjual(){		//program verifikasi akun penjual baru
	system("cls");
	FILE *file_akun_penjual;
	FILE *file_akun_penjual_verified;
	file_akun_penjual = fopen("data penjual.dat", "rb");
	file_akun_penjual_verified = fopen("data penjual terverifikasi.dat", "ab");
	fflush(stdin);
	printf("\n Masukkan Nama Akun yang Ingin Diverifikasi : "); gets(cari);
	while (fread(&penjual,sizeof(penjual),1, file_akun_penjual)==1){
		if (strcmp(penjual.nama, cari)==0){ 
		    fwrite(&penjual, sizeof(penjual), 1, file_akun_penjual_verified);
		}
	}
	
	fclose(file_akun_penjual);
	fclose(file_akun_penjual_verified);
	
	FILE *file_akun_penjual2;
	file_akun_penjual = fopen("data penjual.dat", "rb");
	file_akun_penjual2 = fopen("data penjual2.dat", "wb");
	while (fread(&penjual, sizeof(penjual),1, file_akun_penjual)==1){
		if (strcmp(penjual.nama, cari)!=0){ 
		    fwrite(&penjual, sizeof(penjual), 1, file_akun_penjual2);
		}
	}
 
	fclose(file_akun_penjual);
	fclose(file_akun_penjual2);
	remove("data penjual.dat");
	rename("data penjual2.dat","data penjual.dat");
	printf("\n - Akun Atas Nama '%s' Berhasil Diverifikasi -", cari);
	printf("\n\n=========================================");
	printf("\n\n-Ketik 1 untuk Logout (kembali ke Menu Utama)");
	printf("\n-Ketik 2 untuk Kembali ke halaman Sebelumnya\n");
	printf("Opsi Anda : "); scanf("%d", &ulang);
    switch(ulang){
    	case 1: system("cls"); main(); break;
    	case 2: system("cls"); edit_penjual(); break;
    	default: system("cls");
    		printf("Pilihan yang Anda Masukkan Tidak Tersedia\n"); 
			sleep(2); system("cls"); edit_penjual();
    		break;
	}
}

void list_penjual_verified_admin(){	//program admin untuk melihat daftar akun penejual yang terverifikasi
	system("cls");
	FILE *file_akun_penjual_verified;
	file_akun_penjual_verified = fopen("data penjual terverifikasi.dat", "rb");
	printf(" List Akun Penjual Terverifikasi: \n");
	printf("----------\n\n");
	while(fread(&penjual, sizeof(penjual), 1, file_akun_penjual_verified)==1){
		printf(" Nama : %s\n", penjual.nama);
		printf(" Username : %s\n", penjual.user);
		printf(" Password : %s\n", penjual.pass);
		printf("===================\n");
		printf("\n");
	}
	fclose(file_akun_penjual_verified);
	printf("\n\n=========================================");
	printf("\n\n-Ketik 1 untuk Logout (kembali ke Menu Utama)");
	printf("\n-Ketik 2 untuk Kembali ke halaman Sebelumnya\n");
	printf("Opsi Anda : "); scanf("%d", &ulang);
    switch(ulang){
    	case 1: system("cls"); main(); break;
    	case 2: system("cls"); edit_penjual(); break;
    	default: system("cls");
    		printf("Pilihan yang Anda Masukkan Tidak Tersedia\n"); 
			sleep(2); system("cls"); edit_penjual();
    		break;
	}
}

void hapus_penjual_admin(){		//program admin untuk menghapus akun penjual
	system("cls");
	FILE *file_akun_penjual_verified;
	FILE *file_akun_penjual_verified2;
	file_akun_penjual_verified = fopen("data penjual.dat", "rb");
	file_akun_penjual_verified2 = fopen("data penjual 2.dat", "wb");
	fflush(stdin);
	printf("\n Masukkan nama akun penjual yang ingin dihapus: "); gets(cari);
	while (fread(&penjual,sizeof(penjual),1, file_akun_penjual_verified)==1){
		if (strcmp(penjual.nama, cari)!=0){ 
		    fwrite(&penjual, sizeof(penjual), 1, file_akun_penjual_verified2);
		}
	}
 
	fclose(file_akun_penjual_verified);
	fclose(file_akun_penjual_verified2);
	remove("data penjual terverifikasi.dat");
	rename("data penjual terverifikasi2.dat","data penjual terverifikasi.dat");
	system("cls");
	
	printf("\n\n=========================================");
	printf("\n\n-Ketik 1 untuk Logout (kembali ke Menu Utama)");
	printf("\n-Ketik 2 untuk Kembali ke halaman Sebelumnya\n");
	printf("Opsi Anda : "); scanf("%d", &ulang);
    switch(ulang){
    	case 1: system("cls"); main(); break;
    	case 2: system("cls"); edit_penjual(); break;
    	default: system("cls");
    		printf("Pilihan yang Anda Masukkan Tidak Tersedia\n"); 
			sleep(2); system("cls"); edit_penjual();
    		break;
	}
}

void edit_penjual(){		//program admin untuk opsi edit akun penjual
	system("cls");
	printf("=====   Menu Admin   =====\n");
	printf("==   Edit Akun Penjual   ==\n");
	printf("\n 1. List Akun Penjual yang Belum terverifikasi");
	printf("\n 2. Verifikasi Akun Penjual baru");
	printf("\n 3. List Akun Penjual yang terverifikasi");
	printf("\n 4. Menghapus Akun Penjual");
	printf("\n\n 5. Kembali ke Halaman Sebelumnya");
	printf("\n\n=========================================");
	printf("\n\nMasukkan Pilihan Admin : "); scanf("%d", &pil);
	switch(pil){
		case 1: system("cls"); list_penjual_admin(); break;
		case 2: system("cls"); verifikasi_penjual(); break;
		case 3: system("cls"); list_penjual_verified_admin(); break;
		case 4: system("cls"); hapus_penjual_admin(); break;
		case 5: system("cls"); user_admin(); break;
		default: system("cls"); break;
	}
}

void list_pembeli_admin(){		//program admin untuk melihat daftar akun pembeli
	system("cls");
	FILE *file_akun_pembeli;
	file_akun_pembeli = fopen("data pembeli.dat", "rb");
	printf(" List Akun Pembeli : \n");
	printf("----------\n\n");
	while(fread(&pembeli, sizeof(pembeli), 1, file_akun_pembeli) == 1){
		printf(" Nama : %s\n", pembeli.nama);
		printf(" Username : %s\n", pembeli.user);
		printf(" Password : %s\n", pembeli.pass);
		printf("===================\n");
		printf("\n");
	}
	fclose(file_akun_pembeli);
	printf("\n\n=========================================");
	printf("\n\n-Ketik 1 untuk Logout (kembali ke Menu Utama)");
	printf("\n-Ketik 2 untuk Kembali ke halaman Sebelumnya\n");
	printf("Opsi Anda : "); scanf("%d", &ulang);
    switch(ulang){
    	case 1: system("cls"); main(); break;
    	case 2: system("cls"); edit_pembeli(); break;
    	default: system("cls");
    		printf("Pilihan yang Anda Masukkan Tidak Tersedia\n"); 
			sleep(2); system("cls"); edit_pembeli();
    		break;
	}
}

void hapus_pembeli_admin(){		//program admin untuk menghapus akun pembeli
	system("cls");
	FILE *file_akun_pembeli;
	FILE *file_akun_pembeli2;
	file_akun_pembeli = fopen("data pembeli.dat", "rb");
	file_akun_pembeli2 = fopen("data pembeli 2.dat", "wb");
	fflush(stdin);
	printf("\n Masukkan nama akun pembeli yang ingin dihapus: "); gets(cari);
	while (fread(&pembeli,sizeof(pembeli),1, file_akun_pembeli)==1){
		if (strcmp(pembeli.nama, cari)!=0){ 
		    fwrite(&pembeli, sizeof(pembeli), 1, file_akun_pembeli2);
		}
	}
 
	fclose(file_akun_pembeli);
	fclose(file_akun_pembeli2);
	remove("data pembeli.dat");
	rename("data pembeli 2.dat","data pembeli.dat");
	printf("\n\n=========================================");
	printf("\n\n-Ketik 1 untuk Logout (kembali ke Menu Utama)");
	printf("\n-Ketik 2 untuk Kembali ke halaman Sebelumnya\n");
	printf("Opsi Anda : "); scanf("%d", &ulang);
    switch(ulang){
    	case 1: system("cls"); main(); break;
    	case 2: system("cls"); edit_pembeli(); break;
    	default: system("cls");
    		printf("Pilihan yang Anda Masukkan Tidak Tersedia\n"); 
			sleep(2); system("cls"); edit_pembeli();
    		break;
	}
}

void edit_pembeli(){		//program admin untuk opsi edit akun pembeli
	system("cls");
	printf("=====   Menu Admin   =====\n");
	printf("==   Edit Akun Pembeli   ==\n");
	printf("\n 1. Melihat List Akun Pembeli");
	printf("\n 2. Menghapus Akun Pembeli");
	printf("\n\n 3. Kembali ke Halaman Sebelumnya");
	printf("\n\n=========================================");
	printf("\n\nMasukkan Pilihan Admin : "); scanf("%d", &pil);
	switch(pil){
		case 1: system("cls"); list_pembeli_admin(); break;
		case 2: system("cls"); hapus_pembeli_admin(); break;
		case 3: system("cls"); user_admin(); break;
		default: system("cls"); break;
	}
}

void login_admin(int a){	//program login ke akun admin
	printf("Masukkan Username dan password anda\n");
	printf("       jumlah percobaan (%d)\n\n", a);
	printf("(User = Admin)\n(Pass = Admin)\n");
	if(a >= 1){
		fflush(stdin);
		printf(" Username : "); gets(user_in);
		printf(" Password : "); gets(pass_in);
		check = (strcmp(user_in, "Admin") && strcmp(pass_in, "Admin"));
		if(check == 0){
			system("cls");
			printf("-- Welcome Admin --"); sleep(1); system("cls");
			user_admin();	
		} else {
			printf("\n==| Username atau Password salah! |==\n\n");
			system("pause");
			system("cls");
			login_admin(a-1);
		}
	} else if(a == 0){
		system("cls");
		printf("        == Sudah melebihi batas ! ==");
		sleep(2); system("cls");
		main();
	}
}

void user_admin(){		//program admin buat opsi  fitur admin
	printf("=====   Menu Admin   =====\n");
	printf("\n 1. Edit kategori");		
	printf("\n 2. Edit akun penjual");
	printf("\n 3. Edit akun pembeli");
	printf("\n\n 4. Logout akun Admin (Kembali ke Menu Utama)");
	printf("\n\n=========================================");
	printf("\n\nMasukkan Pilihan Admin : "); scanf("%d", &pil);
	switch(pil){
		case 1: edit_kategori(); break;
		case 2: edit_penjual(); break;
		case 3: edit_pembeli(); break;
		case 4: system ("cls"); printf("= Log-Out Akun Admin.. =\n");
				sleep(1); system("cls"); main(); break;
		default: system("cls"); printf("Opsi Anda Tidak Tersedia..");
				sleep(2); system("cls"); user_admin();
	}	
}

void login_pembeli(int a){		//program login akun pembeli
	printf("     Masukkan Username dan password anda\n");
	printf("           jumlah percobaan (%d)\n\n", a);
	if(a >= 1){
		check_username_pembeli();
		check_password_pembeli();
		fflush(stdin);
		printf(" Username : "); gets(user_in);
		printf(" Password : "); gets(pass_in);
		check = (strcmp(user_in, pembeli.user) && strcmp(pass_in, pembeli.pass));
		if(check == 0){
			system("cls");
			printf("-- Welcome User Pembeli --"); sleep(1); system("cls");
			user_pembeli();	
		} else {
			printf("\n==| Username atau Password salah! |==\n\n");
			system("pause");
			system("cls");
			login_pembeli(a-1);
		}
	} else if(a == 0){
		system("cls");
		printf("        == Sudah melebihi batas ! ==");
		sleep(2); system("cls");
		main();
	}
}

void list_kategori_pembeli(){		//program untuk pembeli melihat daftar barang berdasarkan kategori
	list_kategori();
	
	fflush(stdin);
	printf("\nTuliskan Kategori yang Hendak di Telusuri (<NAMA KATEGORI>.dat): "); gets(cari_kategori);
    list_barang_kategori(cari_kategori);
	
	printf("\n\n=========================================");
	printf("\n-Ketik 1 untuk Logout (kembali ke Menu Utama)");
	printf("\n-Ketik 2 untuk Kembali ke halaman Sebelumnya\n");
	printf("Opsi Anda : "); scanf("%d", &ulang);
    switch(ulang){
    	case 1: system("cls"); main(); break;
    	case 2: system("cls"); user_pembeli(); break;
    	default: system("cls");
    		printf("Pilihan yang Anda Masukkan Tidak Tersedia\n"); 
			sleep(2); system("cls"); user_pembeli();
    		break;
	}
}

void cari_produk(){		//program untuk mencari produk berdasarkan kategori
	list_kategori();
		
	fflush(stdin);
	printf("\nTuliskan Kategori Tempat Barang yang Dicari (<NAMA KATEGORI>.dat) : "); gets(cari_kategori);
	list_barang_kategori(cari_kategori);
	
	FILE *file_kategori;
    file_kategori = fopen(("%s", cari_kategori), "rb");	
	if(file_kategori==NULL){
		printf("File Tidak Ditemukan");
		sleep(2); system("cls"); user_pembeli();
	}
	
	printf("\n Masukkan Nama Barang yang Dicari : "); gets(cari);
	
	while((fread(&kategori,sizeof(kategori), 1, file_kategori)==1)){
		if(strcmp(kategori.barang, cari)==0){
			temu=1;
			printf("\n====== DITEMUKAN ======\n");
		    printf("   Barang : %s\n",kategori.barang);
			printf("   Harga : Rp. %.2f", kategori.harga);
			printf("\n=======================");
			break;
		}
	}
	if (temu==0){
		printf("\n - Barang Tidak Ditemukan - ");
	}
		
    fclose(file_kategori);
    printf("\n\n=========================================");
	printf("\n-Ketik 1 untuk Logout");
	printf("\n-Ketik 2 untuk Kembali ke halaman Sebelumnya\n");
	printf("Opsi Anda : "); scanf("%d", &ulang);
    switch(ulang){
    	case 1: system("cls"); main(); break;
    	case 2: system("cls"); user_pembeli(); break;
    	default: system("cls");
    		printf("Pilihan yang Anda Masukkan Tidak Tersedia\n"); 
			sleep(2); system("cls"); user_pembeli();
    		break;
	}
}

void tambah_troli(){
	list_kategori();
	
	fflush(stdin);
	printf("\nTuliskan Kategori Tempat Barang yang Ingin Ditambahkan ke Troli (<NAMA KATEGORI>.dat) : "); gets(cari_kategori);
	list_barang_kategori(cari_kategori);
	
	fflush(stdin);
	printf("\n Masukkan Nama Barang yang Ingin Ditambahkan ke Troli : "); gets(cari);
	printf("\n Jumlah Barang yang Diambil : "); scanf("%d", &jumlah);
	
	FILE *file_kategori;
	FILE *f_troli;
	file_kategori = fopen(("%s", cari_kategori), "rb");
	f_troli = fopen("troli.dat", "ab");
	while (fread(&kategori,sizeof(kategori),1, file_kategori)==1){
		if (strcmp(kategori.barang, cari)==0){ 
		    fwrite(&kategori, sizeof(kategori), 1, f_troli);
		}
	}
	fclose(file_kategori);
	fclose(f_troli);
	
	printf("\n\n=========================================");
	printf("\n\n-Ketik 1 untuk Logout (kembali ke Menu Utama)");
	printf("\n-Ketik 2 untuk Kembali ke halaman Sebelumnya\n");
	printf("Opsi Anda : "); scanf("%d", &ulang);
    switch(ulang){
    	case 1: system("cls"); main(); break;
    	case 2: system("cls"); menu_troli(); break;
    	default: system("cls");
    		printf("Pilihan yang Anda Masukkan Tidak Tersedia\n"); 
			sleep(2); system("cls"); menu_troli();
    		break;
	}
}

void isi_troli(){
	system("cls");
	FILE *f_troli;
	f_troli = fopen("troli.dat", "rb");
	printf(" List Barang Anda : \n\n");
	while(fread(&kategori,sizeof(kategori),1,f_troli)==1){ 
	    printf(" Barang : %s\n", kategori.barang);
	    printf(" Harga : Rp. %.2f\n", kategori.harga);
	    printf(" Jumlah : %d\n", jumlah);
	    printf("==========\n");
	    printf(" Subtotal Item %s: Rp. %.2f\n", kategori.barang, (kategori.harga*jumlah));
	    printf("\n==========\n");
	} 
	fclose(f_troli);
	
	printf("\n\n - SILAHKAN MENUJU KE KASSA -\n");
	printf("=========================================");
	printf("\n-Ketik 1 untuk Logout");
	printf("\n-Ketik 2 untuk Kembali ke halaman Sebelumnya\n");
	printf("Opsi Anda : "); scanf("%d", &ulang);
    switch(ulang){
    	case 1: system("cls"); main(); break;
    	case 2: system("cls"); menu_troli(); break;
    	default: system("cls");
    		printf("Pilihan yang Anda Masukkan Tidak Tersedia\n"); 
			sleep(2); system("cls"); menu_troli();
    		break;
	}
}

void hapus_troli(){
	system("cls");
	FILE *f_troli;
	FILE *f_troli2;
	f_troli = fopen("troli.dat", "rb");
	f_troli2 = fopen("troli2.dat", "wb");
	fflush(stdin);
	printf("\n Masukkan nama barang yang ingin dihapus: "); gets(cari);
	while (fread(&kategori,sizeof (kategori),1, f_troli)==1){
		if (strcmp(kategori.barang, cari)!=0){ 
		    fwrite(&kategori, sizeof(kategori), 1, f_troli2);
		}
	}
 
	fclose(f_troli);
	fclose(f_troli2);
	remove("troli.dat");
	rename("troli2.dat","troli.dat");
	
	printf("\n\n=========================================");
	printf("\n\n-Ketik 1 untuk Logout");
	printf("\n-Ketik 2 untuk Kembali ke halaman Sebelumnya\n");
	printf("Opsi Anda : "); scanf("%d", &ulang);
    switch(ulang){
    	case 1: system("cls"); main(); break;
    	case 2: system("cls"); menu_troli(); break;
    	default: system("cls");
    		printf("Pilihan yang Anda Masukkan Tidak Tersedia\n"); 
			sleep(2); system("cls"); menu_troli();
    		break;
	}
}

void menu_troli(){
	printf("=====   Menu Troli   =====\n");
	printf("\n 1. Tambahkan Barang\n");
	printf(" 2. Lihat Isi Troli\n");
	printf(" 3. Hapus Barang pada Troli \n\n");
	printf(" 4. Kembali Ke Halaman Sebelumnya\n\n");
	printf(" 5. Log Out Akun Pembeli\n");
	printf("\n Masukkan Opsi Pembeli : "); scanf("%d", &pil);
	switch(pil){
		case 1: system("cls"); tambah_troli(); break;
		case 2: system("cls"); isi_troli(); break;
		case 3: system("cls"); hapus_troli(); break;
		case 4: system("cls"); user_pembeli(); break;
		case 5: system("cls"); main(); break;
	}
}

void user_pembeli(){		//program fitur Pembeli
	printf("=====   Menu Pembeli   =====\n");
	printf("\n 1. Melihat List Barang pada Kategori Pilihan\n");
	printf(" 2. Cari Produk Berdasarkan Kategori \n");
	printf(" 3. Troli\n\n");
	printf(" 4. Log Out Akun Pembeli (Kembali ke Menu Utama)\n");
	printf("\n Masukkan Opsi Pembeli : "); scanf("%d", &pil);
	switch(pil){
		case 1: system("cls"); list_kategori_pembeli(); break;
		case 2: system("cls"); cari_produk(); break;
		case 3: system("cls"); menu_troli(); break;
		case 4: system("cls"); printf(" Log-Out Akun Pembeli...\n"); 
			sleep(2); system("cls"); main(); break;
	}
}

void login_penjual(int a){		//program login akun penjual
	printf("     Masukkan Username dan password anda\n");
	printf("           jumlah percobaan (%d)\n\n", a);
	if(a >= 1){
		check_username_penjual();
		check_password_penjual();
		fflush(stdin);
		printf(" Username : "); gets(user_in);
		printf(" Password : "); gets(pass_in);
		check = (strcmp(user_in, penjual.user) && strcmp(pass_in, penjual.pass));
		if(check == 0){
			system("cls");
			printf("-- Welcome User Penjual --"); sleep(1); system("cls");
			user_penjual();	
		} else {
			printf("\n==| Username atau Password salah! |==\n\n");
			system("pause");
			system("cls");
			login_penjual(a-1);
		}
	} else if(a == 0){
		system("cls");
		printf("        == Sudah melebihi batas ! ==");
		sleep(2); system("cls");
		main();
	}
}

void list_barang_penjual(){
	list_kategori();
		
	fflush(stdin);
	printf("\nTuliskan Kategori yang Ingin di Update (<NAMA KATEGORI>.dat) : "); gets(cari_kategori);
	list_barang_kategori(cari_kategori);
	
	printf("\n\n=========================================");
	printf("\n\n-Ketik 1 untuk Logout (kembali ke Menu Utama)");
	printf("\n-Ketik 2 untuk Kembali ke halaman Sebelumnya\n");
	printf("Opsi Anda : "); scanf("%d", &ulang);
    switch(ulang){
    	case 1: system("cls"); main(); break;
    	case 2: system("cls"); user_penjual(); break;
    	default: system("cls");
    		printf("Pilihan yang Anda Masukkan Tidak Tersedia\n"); 
			sleep(2); system("cls"); user_penjual();
    		break;
	}
}

void tambah_barang_penjual(){  //program Penjual untuk menambah barang di daftar kategori
	list_kategori();
	
	fflush(stdin);
	printf("\nTuliskan Kategori yang Ingin di Update (<NAMA KATEGORI>.dat) : "); gets(cari_kategori);
	list_barang_kategori(cari_kategori);
	
	FILE *file_kategori;
	file_kategori = fopen(("%s", cari_kategori),"ab");
	printf("Banyaknya Barang Tambahan : "); scanf("%d", &n); getchar();
	for (i=1; i<=n; i++){
	    fflush(stdin);
	    printf("\n Barang : "); gets(kategori.barang);
	    printf(" Harga (Rp.) : "); scanf("%lf", &kategori.harga);
	    fwrite(&kategori,sizeof(kategori),1,file_kategori);
	} 
	fclose(file_kategori);
	printf("\n - Barang Baru Telah Ditambahkan Dalam Kategori : %s - \n", cari_kategori);
	printf("\n\n=========================================");
	printf("\n\n-Ketik 1 untuk Logout");
	printf("\n-Ketik 2 untuk Kembali ke halaman Sebelumnya\n");
	printf("Opsi Anda : "); scanf("%d", &ulang);
	   switch(ulang){
	    case 1: system("cls"); main(); break;
	    case 2: system("cls"); user_penjual(); break;
	    default: system("cls");
	     printf("Pilihan yang Anda Masukkan Tidak Tersedia\n"); 
			sleep(2); system("cls"); user_penjual();
	     break;
	   
	}
}

void hapus_barang_penjual(){
	list_kategori();
	
	fflush(stdin);
	printf("\nTuliskan Kategori tempat Barang yang Ingin Dhapus (<NAMA KATEGORI>.dat) : "); gets(cari_kategori);
	list_barang_kategori(cari_kategori);
	
	FILE *file_kategori;
	FILE *file_kategori2;
	file_kategori = fopen(("%s", cari_kategori), "rb");
	file_kategori2 = fopen("file_baru.dat", "wb");
	printf("Tuliskan Nama Barang yang Ingin Dihapus : "); gets(cari);
	while (fread(&kategori,sizeof (kategori),1, file_kategori)==1){
		if (strcmp(kategori.barang, cari)!=0){ 
			fwrite(&kategori, sizeof(kategori), 1, file_kategori2);
		} 
	} 
 
	fclose(file_kategori);
	fclose(file_kategori2);
	remove((("%s", cari_kategori)));
	rename("file_baru.dat",("%s", cari_kategori));
	
	printf("\n - Barang : %s Telah Dihapus dari Kategori : %s - ", cari, cari_kategori);
	
	printf("\n\n=========================================");
	printf("\n\n-Ketik 1 untuk Logout (kembali ke Menu Utama)");
	printf("\n-Ketik 2 untuk Kembali ke halaman Sebelumnya\n");
	printf("Opsi Anda : "); scanf("%d", &ulang);
    switch(ulang){
    	case 1: system("cls"); main(); break;
    	case 2: system("cls"); user_penjual(); break;
    	default: system("cls");
    		printf("Pilihan yang Anda Masukkan Tidak Tersedia\n"); 
			sleep(2); system("cls"); user_penjual();
    		break;
	}
}

void user_penjual(){		//program fitur Penjual
	printf("=====   Menu Penjual   =====\n\n");
	printf(" 1. List Barang pada Kategori Pilihan\n");
	printf(" 2. Menambahkan Barang pada Kategori Pilihan\n");
	printf(" 3. Menghapus Barang pada Kategori Pilihan\n\n");
	printf(" 4. Log Out Akun Penjual (Kembali ke Menu Utama)\n");
	printf("\n Masukkan Opsi Penjual : "); scanf("%d", &pil);
	switch(pil){
	 case 1: system("cls"); list_barang_penjual(); break;
	 case 2: system("cls"); tambah_barang_penjual(); break;
	 case 3: system("cls"); hapus_barang_penjual(); break;
	 case 4: system("cls"); printf(" Log-Out Akun Penjual...\n"); 
			sleep(2); system("cls"); main(); break;
	}
}

int main(){			//program main
	program:
	printf("------------------------------------------------------------------------------\n");
	printf(" DDDD    II   GGGGGGG RRRR       OOOO       CCCC   EEEEEE RRRR    YY      YY\n"); 
	printf(" DD DD  II   GG    GG RR RR     OO  OO     CC  CC  EE     RR RR    YY    YY\n"); 
	printf(" DD  DD     GG        RR  RR   OO    OO   CC       EE     RR  RR    YY  YY\n");
	printf(" DD   DD   GG    GGGG RRRRRRR OO      OO CC        EEEEEE RRRRRRR     YYY\n");
	printf(" DD  DD     GG     GG RR RR    OO    OO   CC       EE     RR RR       YY\n");
	printf(" DD DD       GG    GG RR  RR    OO  OO     CC  CC  EE     RR  RR     YY\n");
	printf(" DDDD         GGGGGG  RR   RR    OOOO       CCCC   EEEEEE RR   RR YYYY\n");
	printf("------------------------------------------------------------------------------\n\n");
	printf("                  =====   WELCOME USER   =====\n"); 
	printf("\n Masuk Sebagai : \n");
	printf("\n 1. Admin");
	printf("\n 2. Penjual");
	printf("\n 3. Pembeli\n");
	printf("\n 4. Registrasi Akun Baru\n");
	printf("\n 5. Keluar\n");
	printf("\nMasukkan Pilihan Anda : "); scanf("%d", &pil);
	system("cls");
	switch(pil){
		case 1:{
			printf("      Selamat Datang Admin !\n");
			login_admin(3);
			user_admin();
			break;
		}
		case 2:{
			printf("== |  Selamat Datang di D'GROCERY Penjual  | ==\n");
			login_penjual(3); break;
		}
		case 3:{
			printf("== |  Selamat Datang di D'GROCERY Pembeli  | ==\n");
			login_pembeli(3); break;
		}
		case 4:{
			registrasi_akun(); break;
		}
		case 5:{
			printf("\n== EXITING PROGRAM... ==\n");
			sleep(1);system("cls"); exit(0);
		}
		default:{
			printf("Pilihan yang Anda Masukkan Tidak Tersedia\n"); 
			sleep(2); system("cls"); main(); break;
		}
	}
	return(0);
}
