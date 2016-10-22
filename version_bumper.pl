use strict;
use warnings;
use File::Spec;

my $file = $ARGV[0] || die "Please supply file name.";
my $abs_path = File::Spec->rel2abs($file);

die ("File doesn't exist") if (! -e $abs_path);

open my $fh, "<", $abs_path || die ("Couldn't open file $file");

my $replacement_line = "!!!ERROR REPLACING VERSION NUMBER";

while (my $line = <$fh>) {
  if ($line =~ m/#define VERSION/) {
    my ($define, $version, $num) = split(/\ /, $line);
    $num = int($num);
    $num += 1;
    $replacement_line = "$define $version $num";
    last;
  }
}

close $fh;

open $fh, "<", $abs_path || die ("Couldn't open file $file");
my $data;

{
  local $/ = undef;
  $data = <$fh>;
}

close $fh;

$data =~ s/#define VERSION ./$replacement_line/g;

open $fh, ">", $abs_path || die ("Couldn't open file $file");
print $fh $data;
close $fh;
