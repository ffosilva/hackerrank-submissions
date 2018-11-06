#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n - 1][m - 1][k - 1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
    return document[m - 1][k - 1];
}

char*** kth_paragraph(char**** document, int k) {
    return document[k - 1];
}

char**** get_document(char* text) {
    int paracount = 0, sentcount = 0, wordcount = 0;
    char *saveptr_para, *saveptr_sent, *saveptr_word;

    char ****document = NULL;

    char *paragraph = strtok_r(text, "\n", &saveptr_para);

    while (paragraph != NULL) {
        paracount += 1;
        if (document == NULL) {
            document = (char ****) malloc(paracount * sizeof(char ***));
        } else {
            document = (char ****) realloc(document, paracount * sizeof(char ***));
        }

        document[paracount - 1] = NULL;
        
        sentcount = 0;
        saveptr_sent = NULL;
        char *sentence = strtok_r(paragraph, ".", &saveptr_sent);
        while (sentence != NULL) {
            sentcount += 1;
            if (document[paracount - 1] == NULL) {
                document[paracount - 1] = (char ***) malloc(sentcount * sizeof(char **));
            } else {
                document[paracount - 1] = (char ***) realloc(document[paracount - 1], sentcount * sizeof(char **));
            }

            document[paracount - 1][sentcount - 1] = NULL;
            
            wordcount = 0;
            saveptr_word = NULL;
            char *word = strtok_r(sentence, " ", &saveptr_word);
            while (word != NULL) {
                wordcount += 1;
                if (document[paracount - 1][sentcount - 1] == NULL) {
                    document[paracount - 1][sentcount - 1] = (char **) malloc(wordcount * sizeof(char *));
                } else {
                    document[paracount - 1][sentcount - 1] = (char **) realloc(document[paracount - 1][sentcount - 1], wordcount * sizeof(char *));
                }

                document[paracount - 1][sentcount - 1][wordcount - 1] = (char *) calloc(strlen(word) + 1, sizeof(char));
                memcpy(document[paracount - 1][sentcount - 1][wordcount - 1], word, strlen(word));
                word = strtok_r(NULL, " ", &saveptr_word);
            }

            sentence = strtok_r(NULL, ".", &saveptr_sent);
        }

        paragraph = strtok_r(NULL, "\n", &saveptr_para);
    }

    return document;
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

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}
