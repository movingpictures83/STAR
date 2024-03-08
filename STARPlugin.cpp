#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "STARPlugin.h"

void STARPlugin::input(std::string file) {
   readParameterFile(file);
}

void STARPlugin::run() {}

void STARPlugin::output(std::string file) {
 std::string outputfile = file;
 std::string myCommand = "";
 //STAR --runThreadN 16 --runMode genomeGenerate --genomeDir genome/ --genomeFastaFiles GCF_000001405.40_GRCh38.p14_rna.fna  --limitGenomeGenerateRAM=124302393618
 //STAR --genomeDir genome/ --readFilesIn S12_R1.fastq S12_R2.fastq --readFilesCommand zcat --runThreadN 16 --outReadsUnmapped Fastx --chimSegmentMin 15 --chimJunctionOverhangMin 15 --outSAMstrandField intronMotif --outSAMtype BAM SortedByCoordinate --outFileNamePrefix align/S1
 if (myParameters.count("runMode") != 0) {
    myCommand += "STAR --runThreadN 16 --runMode genomeGenerate --genomeDir "+file+" --genomeFastaFiles "+PluginManager::addPrefix(myParameters["genomeFasta"])+" --limitGenomeGenerateRAM=124302393618";
 }
 else{
	 myCommand += "STAR --genomeDir "+PluginManager::addPrefix(myParameters["genomeDir"])+" --readFilesIn "+PluginManager::addPrefix(myParameters["fastq1"])+" "+PluginManager::addPrefix(myParameters["fastq2"])+" --readFilesCommand zcat --runThreadN 16 --outReadsUnmapped Fastx --chimSegmentMin 15 --chimJunctionOverhangMin 15 --outSAMstrandField intronMotif --outSAMtype BAM SortedByCoordinate --outFileNamePrefix "+file;
 }
std::cout << myCommand << std::endl;
system(myCommand.c_str());
}

PluginProxy<STARPlugin> STARPluginProxy = PluginProxy<STARPlugin>("STAR", PluginManager::getInstance());
