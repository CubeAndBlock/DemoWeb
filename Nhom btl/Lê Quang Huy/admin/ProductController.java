package com.admin.controller;

import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.HashSet;
import java.util.List;
import java.util.Optional;
import java.util.Set;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

import javax.servlet.http.HttpSession;
import javax.validation.Valid;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageRequest;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import com.entity.Category;
import com.entity.Color;
import com.entity.Product;
import com.entity.Size;
import com.entity.Supply;
import com.model.SearchModel;
import com.request.ProductRequest;
import com.service.CategoryService;
import com.service.FilesStorageService;
import com.service.ProductService;
import com.service.SupplyService;
import com.util.NewsUtil;

@Controller
@RequestMapping("/admin/product")
public class ProductController {

    private static final String POST_URL = "admin/product";
    private final ProductService productService;
    private final CategoryService categoryService;
    private final FilesStorageService storageService;

    @Autowired
    private SupplyService supplyService;

    @Autowired
    public ProductController(ProductService productService, CategoryService categoryService,
                             FilesStorageService storageService) {
        this.productService = productService;
        this.categoryService = categoryService;
        this.storageService = storageService;
    }

    // display list of employees
    @GetMapping
    public String viewList(Model model, HttpSession session, @RequestParam(value = "supplyId", required = false) Integer supplyId,
                           @RequestParam("page") Optional<Integer> page, @RequestParam("size") Optional<Integer> size) {
        int currentPage = page.orElse(1);
        int pageSize = size.orElse(5);
        if (!NewsUtil.isLogin(session)) {
            return "redirect:/login";
        }


        model.addAttribute("supplies", supplyService.list());
        return POST_URL + "/index";
    }

   


    @GetMapping("/view/{id}")
    public String view(@PathVariable("id") int id, Model model, HttpSession session) {
        if (!NewsUtil.isLogin(session)) {
            return "redirect:/login";
        }
        Product product = productService.findById(id);

        model.addAttribute("item", product);

        return POST_URL + "/comment";
    }

}
