void huffman(string C) {
    int n = C.size();
    string Q(C);
    for (int i = 0; i < n; i++) {
        // allocate a new node z
        z.left = x = extract_min(Q);
        z.right = y = extract_min(Q);
        z.freq = x.freq + y.freq;
        insert(Q, z);
    }
    return extract_min(Q);
}