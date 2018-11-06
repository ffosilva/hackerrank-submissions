#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};

struct document get_document(char* text) {
    char *saveptr_para, *saveptr_sent, *saveptr_word;

    struct document *doc = (struct document *) malloc(sizeof(doc));
    doc->paragraph_count = 0;
    doc->data = (struct paragraph *) malloc(5 * sizeof(struct paragraph));

    char *paragraph_str = strtok_r(text, "\n", &saveptr_para);

    while (paragraph_str != NULL) {
        doc->paragraph_count += 1;
        
        struct paragraph *para = &doc->data[doc->paragraph_count - 1];

        para->sentence_count = 0;

        char *sentence_str = strtok_r(paragraph_str, ".", &saveptr_sent);
        while (sentence_str != NULL) {
            para->sentence_count += 1;
            if (para->data == NULL) {
                para->data = (struct sentence *) malloc(para->sentence_count * sizeof(struct sentence));
            } else {
                para->data = (struct sentence *) realloc(para->data, para->sentence_count * sizeof(para));
            }

            struct sentence *sent = &para->data[para->sentence_count - 1];            
            sent->word_count = 0;
            sent->data = (struct word *) malloc(1005 * sizeof(struct word));

            char *word_str = strtok_r(sentence_str, " ", &saveptr_word);
            while (word_str != NULL) {
                sent->word_count += 1;

                struct word *sent_word = &sent->data[sent->word_count - 1];
                sent_word->data = (char *) calloc(strlen(word_str) + 1, sizeof(char));
                memcpy(sent_word->data, word_str, strlen(word_str));

                word_str = strtok_r(NULL, " ", &saveptr_word);
            }

            sentence_str = strtok_r(NULL, ".", &saveptr_sent);
        }

        paragraph_str = strtok_r(NULL, "\n", &saveptr_para);
    }

    return *doc;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n - 1].data[m - 1].data[k - 1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
    return Doc.data[m - 1].data[k - 1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k - 1];
}

void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

int main() 
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }     
}
